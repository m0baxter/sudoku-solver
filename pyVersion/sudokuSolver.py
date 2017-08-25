
import sys
import time
from puzzle import *


block1 = [ (1,1), (1,2), (1,3),
           (2,1), (2,2), (2,3),
           (3,1), (3,2), (3,3) ]

block2 = [ (1,4), (1,5), (1,6),
           (2,4), (2,5), (2,6),
           (3,4), (3,5), (3,6) ]

block3 = [ (1,7), (1,8), (1,9),
           (2,7), (2,8), (2,9),
           (3,7), (3,8), (3,9) ]

block4 = [ (4,1), (4,2), (4,3),
           (5,1), (5,2), (5,3),
           (6,1), (6,2), (6,3) ]

block5 = [ (4,4), (4,5), (4,6),
           (5,4), (5,5), (5,6),
           (6,4), (6,5), (6,6) ]

block6 = [ (4,7), (4,8), (4,9),
           (5,7), (5,8), (5,9),
           (6,7), (6,8), (6,9) ]

block7 = [ (7,1), (7,2), (7,3),
           (8,1), (8,2), (8,3),
           (9,1), (9,2), (9,3) ]

block8 = [ (7,4), (7,5), (7,6),
           (8,4), (8,5), (8,6),
           (9,4), (9,5), (9,6) ]

block9 = [ (7,7), (7,8), (7,9),
           (8,7), (8,8), (8,9),
           (9,7), (9,8), (9,9) ]


def solvePuzzle(puzzle):
    """Solve the sudoku puzzle."""

    return puzzle


if __name__ == "__main__":

    path = sys.argv[1]

    puzzle = Puzzle.fromFile( "test.txt")

    print "Puzzle to solve:"
    puzzle.printPuzzle()

    t1 = time.time()
    solvedPuzzle = solvePuzzle( puzzle )
    t2 = time.time()

    print "Solved puzzle:"
    solvedPuzzle.printPuzzle()

    print "solved in {t}s\n".format(t = t2 - t1)

