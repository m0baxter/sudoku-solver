
#include <vector>
#include <utility>
#include <map>
#include "square.hpp"

#ifndef PUZZLE_HPP
#define PUZZLE_HPP

class Puzzle {

   public:
      Puzzle( std::map< std::pair<int, int>, Square > );
      Puzzle( const char* );
      std::map< std::pair<int,int>, Square> getGrid();
      bool markSquare( const int, const int, const int );
      std::vector< std::pair<int, int> > getUnmarked();
      std::vector< std::pair<int, int> >* getUnmarkedRef();
      bool columnCheck( const int, const int );
      bool rowCheck( const int, const int );
      bool blockCheck( const int, const int );
      bool markable( const int, const int );
      void printPuzzle();

   private:
      static std::vector< std::pair<int,int> > block1;
      static std::vector< std::pair<int,int> > block2;
      static std::vector< std::pair<int,int> > block3;
      static std::vector< std::pair<int,int> > block4;
      static std::vector< std::pair<int,int> > block5;
      static std::vector< std::pair<int,int> > block6;
      static std::vector< std::pair<int,int> > block7;
      static std::vector< std::pair<int,int> > block8;
      static std::vector< std::pair<int,int> > block9;

      std::map< std::pair<int, int>, Square > grid;
      std::vector< std::pair<int, int> > unmarked;
      std::vector< std::pair<int,int> > squareToBlock(const int, const int);
      int getMark( const int, const int );
      bool squareEmpty( const int, const int );
      void updateMarked();
      void genBlocks();

};

#endif

