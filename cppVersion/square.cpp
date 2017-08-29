
#include <set>
#include "square.hpp"


Square::Square( const int m ) {
   /*Creates a Square with marker m. If m == 0 the square is empty.*/

   mark = m;
   possibilities = std::set<int>( {1, 2, 3, 4, 5, 6, 7, 8, 9} );

   if ( mark != 0 ) {
      possibilities = std::set<int>();
   }
}


int Square::getMark() {
   /*Returns the square's marker.*/

   return mark;
}


bool Square::marked() {
   /*Return whether the square is marked.*/

   return mark != 0;
}


std::set<int> Square::getPossibilities() {
   /*eturns a set of possible marks for the square.*/

   return possibilities;
}


bool Square::placeMark( const int m ) {
   /*Mark the square with mark. Returns whether or not the square was successfully marked.*/

   if ( possibilities.find( m ) != possibilities.end() ) {
      mark = m;
      possibilities = std::set<int>();
      return true;
   }

   else {
      return false;
   }
}

