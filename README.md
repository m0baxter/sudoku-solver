# sudoku-solver
A program for solving sudoku puzzles.

## Running

### python

Run with the command

```
python sudokuSolver.py <puzzle>
```

### c++

First build by running

```
make
```

then run with

```
./sudokuSolver <puzzle>
```

In all cases `<puzzle>` is a file of the form

```
1 5 x 8 x 2 x x 7
x 6 x 7 x x x 2 8
x 2 x 5 x 9 x x 3
x 1 2 x x x x 4 5
4 x 3 x 2 x 7 x 1
5 9 x x x x 8 3 x
2 x x 3 x 6 x 8 x
9 3 x x x 8 x 5 x
6 x x 2 x 1 x 7 9
```

which represents the sudoku puzzle

```
   ╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗
   ║ 1 │ 5 │   ║ 8 │   │ 2 ║   │   │ 7 ║
   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
   ║   │ 6 │   ║ 7 │   │   ║   │ 2 │ 8 ║
   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
   ║   │ 2 │   ║ 5 │   │ 9 ║   │   │ 3 ║
   ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
   ║   │ 1 │ 2 ║   │   │   ║   │ 4 │ 5 ║
   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
   ║ 4 │   │ 3 ║   │ 2 │   ║ 7 │   │ 1 ║
   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
   ║ 5 │ 9 │   ║   │   │   ║ 8 │ 3 │   ║
   ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
   ║ 2 │   │   ║ 3 │   │ 6 ║   │ 8 │   ║
   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
   ║ 9 │ 3 │   ║   │   │ 8 ║   │ 5 │   ║
   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
   ║ 6 │   │   ║ 2 │   │ 1 ║   │ 7 │ 9 ║
   ╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝
```

## Test Cases
All test cases were taken from *Sudoku Puzzles*, Vol. 168, Kappa Books 2011. Except those labeled
`hardest` which can be found [here](http://www.sudokuwiki.org/Arto_Inkala_Sudoku).

- One-star puzzles: 1, 14, 19, 22, and 24.
- Two-star puzzles: 29, 32, 36, 40, and 52.
- Three-star puzzles: 55, 59, 68, 72, and 74.
- Four-Star puzzles: 81, 87, 91, 95, and 101.

