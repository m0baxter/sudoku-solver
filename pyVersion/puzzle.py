
# -*- coding: utf-8 -*-
from square import *


class Puzzle(object):

    def __iniit__(self, grid):
        self.grid = grid
        self.solved = False

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

        return puzzle

    def getMark(self, i, j):
        """Returns the marker (or None) of square (i,j)."""

        return self.grid[(i,j)].getMark()

    def squareEmpty(self, i, j):
        """Determine if the square (i,j) is filled."""

        return self.getMark(i,j) == None

    def markSquare(self, i, j, mark):

        self.grid[(i, j)].setMark( mark )

        return

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


if __name__ == "__main__":

    puzzle = Puzzle.fromFile( "test.txt")
    puzzle.printPuzzle()

