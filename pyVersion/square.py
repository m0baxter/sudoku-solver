
class Square(object):

    def __init__(self, mark):
        self.mark = mark
        self.possibilities = range(1,10)

        if ( mark != None ):
            self.possibilities = []

    def getMark(self):

        return self.mark

    def marked(self):
        """Returns whether the square is marked."""

        return self.mark != None

    def possibilities(self):
        """Returns a list of possible marks for the square."""

        return self.possibilities

