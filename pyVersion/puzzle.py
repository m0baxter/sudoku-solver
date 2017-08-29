
# -*- coding: utf-8 -*-
from square import *


class Puzzle(object):

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

    def squareToBlock(self, i, j):

        if ( i in xrange(1,4) and j in xrange(1,4) ):
            return Puzzle.block1

        elif ( i in xrange(1,4) and j in xrange(4,7) ):
            return Puzzle.block2

        elif ( i in xrange(1,4) and j in xrange(7,10) ):
            return Puzzle.block3

        elif ( i in xrange(4,7) and j in xrange(1,4) ):
            return Puzzle.block4

        elif ( i in xrange(4,7) and j in xrange(4,7) ):
            return Puzzle.block5

        elif ( i in xrange(4,7) and j in xrange(7,10) ):
            return Puzzle.block6

        elif ( i in xrange(7,10) and j in xrange(1,4) ):
            return Puzzle.block7

        elif ( i in xrange(7,10) and j in xrange(4,7) ):
            return Puzzle.block8

        elif ( i in xrange(7,10) and j in xrange(7,10) ):
            return Puzzle.block9

    def __iniit__(self, grid):

        self.grid = grid
        self.solved = False
        self.unmarked = [ self.grid.keys()]

        self.updateMarked()

    @classmethod
    def fromFile(cls, path):
        """Reads a sudoku board from a file."""

        grid = {}

        with open(path, 'r') as readFile:

            i = 1

            for line in readFile:

                j = 1
                marks = line.split()

                for m in marks:
                    try:
                        grid[(i,j)] = Square( int(m) )

                    except ValueError:
                        grid[(i,j)] = Square( None )

                    j += 1

                i += 1

        puzzle = Puzzle()
        puzzle.grid = grid
        puzzle.updateMarked()

        return puzzle

    def getMark(self, i, j):
        """Returns the marker (or None) of square (i,j)."""

        return self.grid[(i,j)].getMark()

    def squareEmpty(self, i, j):
        """Determine if the square (i,j) is filled."""

        return self.getMark(i,j) == None

    def markSquare(self, i, j, mark):

        worked = self.grid[(i, j)].placeMark( mark )
        self.updateMarked()

        return worked

    def updateMarked(self):

        self.unmarked = [ (i,j) for i in range(1,10) for j in range(1,10) if self.squareEmpty(i,j) ]

        return

    def getUnmarked(self):

        return self.unmarked

    def columnCheck(self, i, j):
        "Updates the possibilities for square (i,j) based on marks in the column."

        changed = False
        square = self.grid[(i,j)]

        marks = [ self.grid[(i,k)].getMark() for k in range(1,10) ]

        for m in marks:
            try:
                square.possibilities.remove( m )

            except KeyError:
                pass

            else:
                changed = True

        return changed

    def rowCheck(self, i, j):
        "Updates the possibilities for square (i,j) based on marks in the row."

        changed = False
        square = self.grid[(i,j)]

        marks = [ self.grid[(k,j)].getMark() for k in range(1,10) ]

        for m in marks:
            try:
                square.possibilities.remove( m )

            except KeyError:
                pass

            else:
                changed = True

        return changed

    def blockCheck(self, i, j):

        changed = False
        square = self.grid[(i,j)]

        marks = [ self.grid[s].getMark() for s in self.squareToBlock(i,j) if self.grid[s].getMark() != None ]

        for m in marks:
            try:
                square.possibilities.remove( m )

            except KeyError:
                pass

            else:
                changed = True

        return changed

    def markable(self, i, j):
        """Determines if the square (i,j) can be marked."""

        possible = self.grid[(i,j)].getPossibilities()

        if ( len(possible) == 1 ):
            marked = self.markSquare( i, j, list(possible)[0] )

            return marked

        else:
            return False

    def printPuzzle(self):
        """Prints the puzzle board."""

        puzzle = "\n   ╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(1, 1), self.getMark(1, 2), self.getMark(1, 3),
                                                                                        self.getMark(1, 4), self.getMark(1, 5), self.getMark(1, 6),
                                                                                        self.getMark(1, 7), self.getMark(1, 8), self.getMark(1, 9) ) + \
                 "\n   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(2, 1), self.getMark(2, 2), self.getMark(2, 3),
                                                                                        self.getMark(2, 4), self.getMark(2, 5), self.getMark(2, 6),
                                                                                        self.getMark(2, 7), self.getMark(2, 8), self.getMark(2, 9) ) + \
                 "\n   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(3, 1), self.getMark(3, 2), self.getMark(3, 3),
                                                                                        self.getMark(3, 4), self.getMark(3, 5), self.getMark(3, 6),
                                                                                        self.getMark(3, 7), self.getMark(3, 8), self.getMark(3, 9) ) + \
                 "\n   ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(4, 1), self.getMark(4, 2), self.getMark(4, 3),
                                                                                        self.getMark(4, 4), self.getMark(4, 5), self.getMark(4, 6),
                                                                                        self.getMark(4, 7), self.getMark(4, 8), self.getMark(4, 9) ) + \
                 "\n   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(5, 1), self.getMark(5, 2), self.getMark(5, 3),
                                                                                        self.getMark(5, 4), self.getMark(5, 5), self.getMark(5, 6),
                                                                                        self.getMark(5, 7), self.getMark(5, 8), self.getMark(5, 9) ) + \
                 "\n   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(6, 1), self.getMark(6, 2), self.getMark(6, 3),
                                                                                        self.getMark(6, 4), self.getMark(6, 5), self.getMark(6, 6),
                                                                                        self.getMark(6, 7), self.getMark(6, 8), self.getMark(6, 9) ) + \
                 "\n   ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(7, 1), self.getMark(7, 2), self.getMark(7, 3),
                                                                                        self.getMark(7, 4), self.getMark(7, 5), self.getMark(7, 6),
                                                                                        self.getMark(7, 7), self.getMark(7, 8), self.getMark(7, 9) ) + \
                 "\n   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(8, 1), self.getMark(8, 2), self.getMark(8, 3),
                                                                                        self.getMark(8, 4), self.getMark(8, 5), self.getMark(8, 6),
                                                                                        self.getMark(8, 7), self.getMark(8, 8), self.getMark(8, 9) ) + \
                 "\n   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" + \
                 "\n   ║ {0} │ {1} │ {2} ║ {3} │ {4} │ {5} ║ {6} │ {7} │ {8} ║".format( self.getMark(9, 1), self.getMark(9, 2), self.getMark(9, 3),
                                                                                        self.getMark(9, 4), self.getMark(9, 5), self.getMark(9, 6),
                                                                                        self.getMark(9, 7), self.getMark(9, 8), self.getMark(9, 9) ) + \
                 "\n   ╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n"

        print puzzle.replace( "None", " ")

        return

