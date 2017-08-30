
import sys
import time
import copy
from puzzle import *


def solvePuzzle(puzzle):
    """Solve the sudoku puzzle."""

    queue = [ copy.deepcopy( puzzle ) ]

    for p in queue:

        puzzleChanged = True

        while (puzzleChanged):

            puzzleChanged = False

            for s in p.getUnmarked():

                check1 = p.columnCheck( *s )
                check2 = p.rowCheck( *s )
                check3 = p.blockCheck( *s )
                check4 = p.markable( *s )

                puzzleChanged = any( [check1, check2, check3, check4] )

        unmarked = p.getUnmarked()

        if ( len(unmarked) == 0 ):
            print "here1"
            return p

        else:
            s = unmarked.pop()
            possible = p.grid[s].getPossibilities()

            for m in possible:
                pGuess = copy.deepcopy( p )
                pGuess.markSquare( s[0], s[1], m )

                if ( len(pGuess.getUnmarked()) == 0 ):
                    print "here2"
                    return pGuess
                queue.append( pGuess )

    print "here3"
    return queue[0]


if __name__ == "__main__":

    path = sys.argv[1]

    puzzle = Puzzle.fromFile( path )

    print "Puzzle to solve:"
    puzzle.printPuzzle()

    t1 = time.time()
    solvedPuzzle = solvePuzzle( puzzle )
    t2 = time.time()

    print "Solved puzzle:"
    solvedPuzzle.printPuzzle()

    print "solved in {t}s\n".format(t = t2 - t1)

