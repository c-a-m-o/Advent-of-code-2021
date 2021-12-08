read_input_line(Line) :-
    read_string(user_input, "\n", "\r", _, Line).

% Reads a line and converts it to a number
read_num(Num):-
    read_input_line(String),
    number_string(Num, String).

% Reads first 3 elements
init_mem(Fi, Se, Th) :-
    read_num(Fi),
    read_num(Se),
    read_num(Th).


solve(Fi, Se, Th, Res) :-
    solve(Fi, Se, Th, 0, Res).


solve(Fi, Se, Th, Acc, Res) :-
    read_num(Num),
    !,
    process(Fi, Se, Th, Num, Acc, Res).

% Only if read_num failed (eof) : stop and returns the count
solve(_, _, _, Res, Res).
    
process(Fi, Se, Th, Num, Acc, Res) :-
    Num > Fi,
    !,
    NewAcc is Acc + 1,
    solve(Se, Th, Num, NewAcc, Res).

% Only if Fi greater than Num, we call solve without adding one to
% the count
process(_, Se, Th, Num, Acc, Res) :-
    solve(Se, Th, Num, Acc, Res).
    
main():-
    init_mem(Fi, Se, Th),
    solve(Fi, Se, Th, Res),
    write(Res),
    halt.

:- main.
% If errors in main
:- halt.
