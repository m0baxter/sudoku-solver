
class Square(object):

    def __init__(self, mark):
        self.mark = mark
        self.possibilities = set( range(1,10) )

        if ( mark != None ):
            self.possibilities = set( [] )

    def getMark(self):

        return self.mark

    def marked(self):
        """Returns whether the square is marked."""

        return self.mark != None

    def possibilities(self):
        """Returns a list of possible marks for the square."""

        return self.possibilities

    def placeMark(self, mark):
        """Mark the square with mark. Returns whether or not the square was successfully marked."""

        if ( mark in self.possibilities() ):
            self.mark = mark
            self.possibilities = set([])

            return True

        else:
            return False

