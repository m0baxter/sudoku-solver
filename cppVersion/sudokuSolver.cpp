
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
#include "puzzle.hpp"


Puzzle solvePuzzle( Puzzle puzzle ) {
   /*Solve the sudoku puzzle.*/

   std::queue<Puzzle> queue;
   queue.push( puzzle );

   while ( not queue.empty() ) {

      Puzzle p = queue.front();
      queue.pop();

      bool puzzleChanged = true;

      while (puzzleChanged) {

         puzzleChanged = false;

         for ( auto &s : p.getUnmarked() ) {

            puzzleChanged |= p.columnCheck( s.first, s.second );
            puzzleChanged |= p.rowCheck( s.first, s.second );
            puzzleChanged |= p.blockCheck( s.first, s.second );
            puzzleChanged |= p.markable( s.first, s.second );
         }
      }

      std::vector< std::pair<int,int> > *unmarked = p.getUnmarkedRef();

      if ( (*unmarked).size() == 0 ) {
         return p;
      }
      else {
         std::pair<int,int> s = (*unmarked).front();
         (*unmarked).erase( (*unmarked).begin() );
         std::set<int> possible = p.getGrid().at(s).getPossibilities();

         for (auto &m : possible) {
            Puzzle pGuess(p);
            pGuess.markSquare( s.first, s.second, m );

            if ( pGuess.getUnmarked().size() == 0 ) {
               return pGuess;
            }

            queue.push( pGuess );
         }
      }
   }

   return queue.front();
}


int main ( int argc, char* argv[] ) {

   Puzzle puzzle( argv[1] );

   std::cout << "\nPuzzle to solve:" <<std::endl;
   puzzle.printPuzzle();

   Puzzle solvedPuzzle = solvePuzzle( puzzle );

   std::cout << "Solved puzzle:" <<std::endl;
   solvedPuzzle.printPuzzle();

   return 0;
}

