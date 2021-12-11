# Advent of code 2021

Here are my solutions for the 2021 edition of the [Advent of Code](https://adventofcode.com/2021/).
I will try to write a solution for every exercice in `C++`. When the problem is not too difficult,
I will also try to [golf](https://en.wikipedia.org/wiki/Code_golf) it in `Ruby`.
I will also solve some of the exercices in `Rust` and `Prolog` if I get the time.

There is a batch (so windows-only for now) script to automatically run a solution if it is implemented.
To use it, you first need to put your input in a file called `dayX.txt` (`X` is the number of the day) in a folder called `input`. Then type

```batch
.\run.bat <lang> <day> <part>
```
In the command line at the root of the project.

`lang` is one of `c++`, `cpp`, `ruby`, `prolog`, and `rust`, `day` is a number between `1` and `25` and `part` is either `1` or `2`.

## Requirements

- To compile and run the `c++` solutions, you need to have `g++` installed and in the `PATH`.
- To compile and run the `Rust` solutions, you need to have `Rust` installed and `rustc` in the path.
- To run the `prolog` solutions, you need to have `swipl` (from SWI-Prolog) installed and in the `PATH`.
- To run the `Ruby` solutions, you need to have `ruby` installed and on the path.

## Completed exercices :

| Day | C++ | Ruby | Prolog | Rust | Golf pt.1 | Golf pt.2|
|-----|-----|------|--------|------|-----------|----------|
|    1|✅✅|✅✅ |   ❌✅| ✅✅|        39B|       39B|
|    2|✅✅|✅✅ |   ❌❌| ❌❌|        64B|       75B|
|    3|✅✅|❌❌ |   ❌❌| ❌❌|        N/A|       N/A|
|    4|✅✅|✅❌ |   ❌❌| ❌❌|       237B|       N/A|
|    5|✅✅|✅❌ |   ❌❌| ❌❌|        WIP|       N/A|
|    6|✅✅|✅✅ |   ❌❌| ❌❌|        76B|       77B|
|    7|✅✅|✅✅ |   ❌❌| ❌❌|        52B|       76B|
|    8|✅✅|✅✅ |   ❌❌| ❌❌|        47B|      212B|
|    9|✅✅|❌❌ |   ❌❌| ❌❌|        N/A|       N/A|
|   10|✅✅|❌❌ |   ✅✅| ❌❌|        N/A|       N/A|
|   11|✅✅|❌❌ |   ❌❌| ❌❌|        N/A|       N/A|
