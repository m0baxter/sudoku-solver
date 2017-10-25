
#include <vector>
#include <utility>
#include <map>
#include <iostream>
#include <fstream>
#include "StringManipulators.hpp"
#include "keysNvals.hpp"
#include "square.hpp"
#include "puzzle.hpp"


bool inRange( const int i, const int lower, const int upper ) {
   /*Determines whether lower <= i <= upper.*/

   return (unsigned)(i - lower) <= (upper - lower);
}


Puzzle::Puzzle( std::map< std::pair<int, int>, Square > grd ) {
   /*Creates a sudoku puzzle object from a map representing the puzzle board.*/

   grid = grd;
   unmarked = getKeys< std::pair<int,int>, Square >( grid );
   genBlocks();
   updateMarked();
}

Puzzle::Puzzle( const Puzzle& p ) {
   /*Copy constructor for Puzzle. Performs a deep copy.*/

   std::map< std::pair<int, int>, Square >  oldGrid = p.getGrid();
   std::map< std::pair<int, int>, Square > newGrid;

   std::vector< std::pair<int,int> > keys = getKeys< std::pair<int,int>, Square >( oldGrid );

   for ( auto &k : keys ) {

      Square oldSquare = oldGrid.at( k );
      Square newSquare = Square( oldSquare.getMark() );

      newGrid[k] = newSquare;
   }

   grid = newGrid;
   unmarked = keys;
   genBlocks();
   updateMarked();
}


Puzzle::Puzzle( const char* path ) {
   /*Reads a puzzle from a file.*/

   std::map< std::pair<int,int>, Square> puzzle;

   std::ifstream readFile( path );
   std::string line;

   int i = 1;

   while ( std::getline(readFile, line) ) {

      std::vector<std::string> marks = split( line, " " );
      int j = 1;

      for ( auto &m : marks ) {

         puzzle[ std::make_pair(i,j) ] = Square( str_to<int>( m ) );
         ++j;
      }

      ++i;
   }

   grid = puzzle;
   unmarked = getKeys< std::pair<int,int>, Square >( grid );
   genBlocks();
   updateMarked();
}


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


std::map< std::pair<int,int>, Square > Puzzle::getGrid() const {
   /*Returns the puzzle grid.*/

   return grid;
}


int Puzzle::getMark( const int i, const int j ) {
   /*Returns the marker in square (i, j).*/

   return grid.at( std::make_pair(i,j) ).getMark();
}


bool Puzzle::squareEmpty( const int i , const int j ) {
   /*Determines whether or not the square is empty.*/

   return getMark(i,j) == 0;
}


void Puzzle::updateMarked() {
   /*Updates the vector of unmarked squares.*/

   std::vector< std::pair<int,int> > newUnmarked;

   for (auto &s : unmarked) {
      if ( squareEmpty(s.first, s.second) ) {
         newUnmarked.push_back( s );
      }
   }

   unmarked = newUnmarked;
}


bool Puzzle::markSquare( const int i, const int j, const int m ) {
   /*Places the mark m in square (i,j) if possible.*/
   
   bool marked = grid.at( std::make_pair(i,j) ).placeMark( m );
   updateMarked();

   return marked;
}


std::vector< std::pair<int, int> > Puzzle::getUnmarked() const {
   /*Returns the vector of unmarked squares.*/

   return unmarked;
}


std::vector< std::pair<int, int> >* Puzzle::getUnmarkedRef() {
   /*Returns the vector of unmarked squares.*/

   return &unmarked;
}

bool Puzzle::columnCheck( const int i, const int j ) {
   /*Updates the possibilities for square (i,j) based on marks in the column.*/

   bool changed = false;
   std::set<int> *possibilities = grid.at( std::make_pair(i,j) ).getPossibilitiesRef();

   //Collect all marks in the column:
   for (int k = 1; k < 10; ++k ) {
      int mark = grid.at( std::make_pair(k,j) ).getMark();

      changed |= (*possibilities).erase(mark);
   }

   return changed;
}


bool Puzzle::rowCheck( const int i, const int j ) {
   /*Updates the possibilities for square (i,j) based on marks in the row.*/

   bool changed = false;
   std::set<int> *possibilities = grid.at( std::make_pair(i,j) ).getPossibilitiesRef();

   //Collect all marks in the row:
   for (int k = 1; k < 10; ++k ) {
      int mark = grid.at( std::make_pair(i,k) ).getMark();

      changed |= (*possibilities).erase(mark);
   }

   return changed;
}


bool Puzzle::blockCheck( const int i, const int j ) {
   /*Updates the possibilities for square (i,j) based on marks in the block.*/

   bool changed = false;
   std::vector<int> marks;
   std::set<int> *possibilities = grid.at( std::make_pair(i,j) ).getPossibilitiesRef();

   //Collect all marks in the block:
   for ( auto &s : squareToBlock(i,j) ) {
      int mark = grid.at( s ).getMark();

      changed |= (*possibilities).erase(mark);
   }

   return changed;
}


bool Puzzle::markable( const int i, const int j ) {
   /*Determines if the square (i,j) can be marked.*/

   std::set<int> possible =  grid.at( std::make_pair(i,j) ).getPossibilities();
   //printPuzzle();

   if ( possible.size() == 1 ) {
      return markSquare( i, j, *possible.begin() );
   }
   else {
      return false;
   }
}


void Puzzle::printPuzzle() {

   std::cout << std::endl;
   std::cout << "   ╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗" << std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(1,1)).toString() << + " │ " + grid.at(std::make_pair(1,2)).toString() + " │ " + grid.at(std::make_pair(1,3)).toString() + " ║ " + grid.at(std::make_pair(1,4)).toString() + " │ " + grid.at(std::make_pair(1,5)).toString() + " │ " + grid.at(std::make_pair(1,6)).toString() + " ║ " + grid.at(std::make_pair(1,7)).toString() + " │ " + grid.at(std::make_pair(1,8)).toString() + " │ " + grid.at(std::make_pair(1,9)).toString() + " ║" << std::endl;
   std::cout << "   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(2,1)).toString() + " │ " + grid.at(std::make_pair(2,2)).toString() + " │ " + grid.at(std::make_pair(2,3)).toString() + " ║ " + grid.at(std::make_pair(2,4)).toString() + " │ " + grid.at(std::make_pair(2,5)).toString() + " │ " + grid.at(std::make_pair(2,6)).toString() + " ║ " + grid.at(std::make_pair(2,7)).toString() + " │ " + grid.at(std::make_pair(2,8)).toString() + " │ " + grid.at(std::make_pair(2,9)).toString() + " ║" << std::endl;
   std::cout << "   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(3,1)).toString() + " │ " + grid.at(std::make_pair(3,2)).toString() + " │ " + grid.at(std::make_pair(3,3)).toString() + " ║ " + grid.at(std::make_pair(3,4)).toString() + " │ " + grid.at(std::make_pair(3,5)).toString() + " │ " + grid.at(std::make_pair(3,6)).toString() + " ║ " + grid.at(std::make_pair(3,7)).toString() + " │ " + grid.at(std::make_pair(3,8)).toString() + " │ " + grid.at(std::make_pair(3,9)).toString() + " ║" << std::endl;
   std::cout << "   ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣" << std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(4,1)).toString() + " │ " + grid.at(std::make_pair(4,2)).toString() + " │ " + grid.at(std::make_pair(4,3)).toString() + " ║ " + grid.at(std::make_pair(4,4)).toString() + " │ " + grid.at(std::make_pair(4,5)).toString() + " │ " + grid.at(std::make_pair(4,6)).toString() + " ║ " + grid.at(std::make_pair(4,7)).toString() + " │ " + grid.at(std::make_pair(4,8)).toString() + " │ " + grid.at(std::make_pair(4,9)).toString() + " ║" << std::endl;
   std::cout << "   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(5,1)).toString() + " │ " + grid.at(std::make_pair(5,2)).toString() + " │ " + grid.at(std::make_pair(5,3)).toString() + " ║ " + grid.at(std::make_pair(5,4)).toString() + " │ " + grid.at(std::make_pair(5,5)).toString() + " │ " + grid.at(std::make_pair(5,6)).toString() + " ║ " + grid.at(std::make_pair(5,7)).toString() + " │ " + grid.at(std::make_pair(5,8)).toString() + " │ " + grid.at(std::make_pair(5,9)).toString() + " ║" << std::endl;
   std::cout << "   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(6,1)).toString() + " │ " + grid.at(std::make_pair(6,2)).toString() + " │ " + grid.at(std::make_pair(6,3)).toString() + " ║ " + grid.at(std::make_pair(6,4)).toString() + " │ " + grid.at(std::make_pair(6,5)).toString() + " │ " + grid.at(std::make_pair(6,6)).toString() + " ║ " + grid.at(std::make_pair(6,7)).toString() + " │ " + grid.at(std::make_pair(6,8)).toString() + " │ " + grid.at(std::make_pair(6,9)).toString() + " ║" << std::endl;
   std::cout << "   ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣" << std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(7,1)).toString() + " │ " + grid.at(std::make_pair(7,2)).toString() + " │ " + grid.at(std::make_pair(7,3)).toString() + " ║ " + grid.at(std::make_pair(7,4)).toString() + " │ " + grid.at(std::make_pair(7,5)).toString() + " │ " + grid.at(std::make_pair(7,6)).toString() + " ║ " + grid.at(std::make_pair(7,7)).toString() + " │ " + grid.at(std::make_pair(7,8)).toString() + " │ " + grid.at(std::make_pair(7,9)).toString() + " ║" << std::endl;
   std::cout << "   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" <<std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(8,1)).toString() + " │ " + grid.at(std::make_pair(8,2)).toString() + " │ " + grid.at(std::make_pair(8,3)).toString() + " ║ " + grid.at(std::make_pair(8,4)).toString() + " │ " + grid.at(std::make_pair(8,5)).toString() + " │ " + grid.at(std::make_pair(8,6)).toString() + " ║ " + grid.at(std::make_pair(8,7)).toString() + " │ " + grid.at(std::make_pair(8,8)).toString() + " │ " + grid.at(std::make_pair(8,9)).toString() + " ║" << std::endl;
   std::cout << "   ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" <<std::endl;
   std::cout << "   ║ " + grid.at(std::make_pair(9,1)).toString() + " │ " + grid.at(std::make_pair(9,2)).toString() + " │ " + grid.at(std::make_pair(9,3)).toString() + " ║ " + grid.at(std::make_pair(9,4)).toString() + " │ " + grid.at(std::make_pair(9,5)).toString() + " │ " + grid.at(std::make_pair(9,6)).toString() + " ║ " + grid.at(std::make_pair(9,7)).toString() + " │ " + grid.at(std::make_pair(9,8)).toString() + " │ " + grid.at(std::make_pair(9,9)).toString() + " ║" << std::endl;
   std::cout << "   ╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝" << std::endl;

}


void Puzzle::genBlocks() {
   /*Generates the blocks.*/

   block1 = { std::make_pair(1,1), std::make_pair(1,2), std::make_pair(1,3),
              std::make_pair(2,1), std::make_pair(2,2), std::make_pair(2,3),
              std::make_pair(3,1), std::make_pair(3,2), std::make_pair(3,3) };

   block2 = { std::make_pair(1,4), std::make_pair(1,5), std::make_pair(1,6),
              std::make_pair(2,4), std::make_pair(2,5), std::make_pair(2,6),
              std::make_pair(3,4), std::make_pair(3,5), std::make_pair(3,6) };

   block3 = { std::make_pair(1,7), std::make_pair(1,8), std::make_pair(1,9),
              std::make_pair(2,7), std::make_pair(2,8), std::make_pair(2,9),
              std::make_pair(3,7), std::make_pair(3,8), std::make_pair(3,9) };

   block4 = { std::make_pair(4,1), std::make_pair(4,2), std::make_pair(4,3),
              std::make_pair(5,1), std::make_pair(5,2), std::make_pair(5,3),
              std::make_pair(6,1), std::make_pair(6,2), std::make_pair(6,3) };

   block5 = { std::make_pair(4,4), std::make_pair(4,5), std::make_pair(4,6),
              std::make_pair(5,4), std::make_pair(5,5), std::make_pair(5,6),
              std::make_pair(6,4), std::make_pair(6,5), std::make_pair(6,6) };

   block6 = { std::make_pair(4,7), std::make_pair(4,8), std::make_pair(4,9),
              std::make_pair(5,7), std::make_pair(5,8), std::make_pair(5,9),
              std::make_pair(6,7), std::make_pair(6,8), std::make_pair(6,9) };

   block7 = { std::make_pair(7,1), std::make_pair(7,2), std::make_pair(7,3),
              std::make_pair(8,1), std::make_pair(8,2), std::make_pair(8,3),
              std::make_pair(9,1), std::make_pair(9,2), std::make_pair(9,3) };

   block8 = { std::make_pair(7,4), std::make_pair(7,5), std::make_pair(7,6),
              std::make_pair(8,4), std::make_pair(8,5), std::make_pair(8,6),
              std::make_pair(9,4), std::make_pair(9,5), std::make_pair(9,6) };

   block9 = { std::make_pair(7,7), std::make_pair(7,8), std::make_pair(7,9),
              std::make_pair(8,7), std::make_pair(8,8), std::make_pair(8,9),
              std::make_pair(9,7), std::make_pair(9,8), std::make_pair(9,9) };

}

