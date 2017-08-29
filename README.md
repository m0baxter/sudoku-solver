# sudoku-solver
A program for solving sudoku puzzles.

##Python

Run with the command

'''
python sudokuSolver.py <puzzle>
'''

where '<puzzle>' is a file of the form

'''
x x x 9 4 x x x x
x 4 x x x x 3 x 1
x 5 x 1 x x x 8 x
x x x 3 2 x 8 x x
8 x 2 x x x 7 x 9
x x 9 x 7 1 x x x
x 3 x x x 6 x 5 x
5 x 4 x x x x 9 x
x x x x 8 4 x x x
'''

which represents the sudoku puzzle

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

## Test Cases
All test cases were taken from *Sudoku Puzzles*, Vol. 168, Kappa Books 2011.

-One-star puzzles: 1, 14, 19, 22, and 24.
-Two-star puzzles: 29, 32, 36, 40, and 52.
-Three-star puzzles: 55, 59, 68, 72, and 74.
-Four-Star puzzles: 81, 87, 91, 95, and 101.

