
#include <vector>
#include <utility>
#include <map>
#include "puzzle.hpp"


Puzzle::Puzzle( std::map< std::pair<int, int>, Square > grd ) {
   /*Creates a sudoku puzzle object from a map representing the puzzle board.*/

   grid = grd;
   unmarked = getKeys< std::pair<int,int>, int >( grid );
   updateMarked();
}

//do this v
Puzzle( const char* );
//do this ^

std::vector< std::pair<int,int> > Puzzle::squareToBlock( const int i, const int j ) {
   /*Returns the block to which the square (i,j) belongs.*/

   if ( inRange(i,1,3) && inRange(j,1,3) ) {
      return block1;
   }
   else if ( inRange(i,1,3) && inRange(j,4,6) ) {
      return block2;
   }
   else if ( inRange(i,1,3) && inRange(j,7,9) ) {
      return block3;
   }
   else if ( inRange(i,4,6) && inRange(j,1,3) ) {
      return block4;
   }
   else if ( inRange(i,4,6) && inRange(j,4,6) ) {
      return block5;
   }
   else if ( inRange(i,4,6) && inRange(j,7,9) ) {
      return block6;
   }
   else if ( inRange(i,7,9) && inRange(j,1,3) ) {
      return block7;
   }
   else if ( inRange(i,7,9) && inRange(j,4,6) ) {
      return block8;
   }
   else if ( inRange(i,7,9) && inRange(j,7,9) ) {
      return block9;
   }
}


int getMark( const int, const int ) {
   /*Returns the marker in square (i, j).*/

   return grid.at( std::make_pair(i,j) ).getMark();
}


bool squareEmpty( const int, const int ) {
   /*Determines whether or not the square is empty.*/

   return getMark(i,j) == 0;
}


void updateMarked() {
   /*Updates the vector of unmarked squares.*/

   newUnmarked = std::vector< std::pair<int,int> >;

   for (auto &s : unmarked) {
      if ( squareEmpty(s.first, s.second) ) {
         newUnmarked.push_back( s );
      }
   }

   unmarked = newUnmarked;
}


//do this v
bool markSquare( const int, const int, const int );
//do this ^


std::vector< std::pair<int, int> > getUnmarked() {
   /*Returns the vector of unmarked squares.*/

   return unmarked;
}


bool columnCheck( const int, const int );
bool rowCheck( const int, const int );
bool blockCheck( const int, const int );
bool markable( const int, const int );
void printPuzzle();


bool inRange( const int i, const int lower, const int upper ) {
   /*Determines whether lower <= i <= upper.*/

   return (unsigned)(i - lower) <= (upper - lower);
}

