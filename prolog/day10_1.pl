validate(Line) :-
    Line == "",
    !,
    fail.

validate(_).

read_input_line(Line) :-
    read_string(user_input, "\n", "\r", _, Line).

matching('(', ')').
matching('[', ']').
matching('{', '}').
matching('<', '>').

points(')', 3).
points(']', 57).
points('}', 1197).
points('>', 25137).

% If RH is a closing delimiter
consume([RH|LT], [RH|RT], Res):-
    !, % It works, don't try the fallback case
    consume(LT, RT, Res).

% If RH is an opening delimiter
consume(L, [RH|RT], Res):-
    matching(RH, Closing),
    consume([Closing|L], RT, Res).

% fallback case : the opening does not match
consume(_, [RH|_], Res):-
    points(RH, Res).

% Incomplete lines are not treated yet
consume(_, [], 0).


process_line(Line, Res):-
    string_chars(Line, Chars),
    consume([], Chars, Res).

solve(Acc, Res):-
    read_input_line(Line),
    validate(Line),
    !,
    process_line(Line, Val),
    NewAcc is Acc + Val,
    solve(NewAcc, Res).

solve(Res, Res).

main:-
    solve(0, Res),
    write(Res),
    write("\n"),
    halt.
    
main:-
    halt.

:- main.