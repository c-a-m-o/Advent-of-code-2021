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

points(')', 1).
points(']', 2).
points('}', 3).
points('>', 4).

score([], Acc, Acc).
score([H|T], Acc, Res):-
    points(H, P),
    NewAcc is Acc * 5 + P,
    score(T, NewAcc, Res).
% score([], 0).
% score([H|T], Res):-
%     score(T, Tmp),
%     points(H, P),
%     Res is Tmp * 5 + P.

% If RH is a closing delimiter
consume([RH|LT], [RH|RT], Res):-
    !, % It works, don't try the fallback case
    consume(LT, RT, Res).

% If RH is an opening delimiter
consume(L, [RH|RT], Res):-
    matching(RH, Closing),
    consume([Closing|L], RT, Res).

% Corrupted lines do not count
% [_|_] => Non-empty list
consume(_, [_|_], 0).

% Incomplete lines
consume(L, [], Res):-
    score(L, 0, Res).
    % score(L, Res).


process_line(Line, Res):-
    string_chars(Line, Chars),
    consume([], Chars, Res).

put_in_acc_if_not_0(0, Acc, Acc):-
    !.
    
put_in_acc_if_not_0(Val, Acc, [Val|Acc]).

solve(Acc, Res):-
    read_input_line(Line),
    validate(Line),
    !,
    process_line(Line, Val),
    put_in_acc_if_not_0(Val, Acc, NewAcc),
    solve(NewAcc, Res).

solve(L, Res):-
    sort(L, S),
    length(L, N),
    Pos is N // 2,
    nth0(Pos, S, Res).
        

main:-
    solve([], Res),
    write(Res),
    write("\n"),
    halt.
    
main:-
    halt.

:- main.