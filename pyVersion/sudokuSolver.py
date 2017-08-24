
import sys
import time
from puzzle import *


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

