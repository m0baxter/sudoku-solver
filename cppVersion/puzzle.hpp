
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
      Puzzle( const Puzzle& );
      std::map< std::pair<int,int>, Square> getGrid() const;
      bool markSquare( const int, const int, const int );
      std::vector< std::pair<int, int> > getUnmarked() const;
      std::vector< std::pair<int, int> >* getUnmarkedRef();
      bool columnCheck( const int, const int );
      bool rowCheck( const int, const int );
      bool blockCheck( const int, const int );
      bool markable( const int, const int );
      void printPuzzle();

   private:
      std::vector< std::pair<int,int> > block1;
      std::vector< std::pair<int,int> > block2;
      std::vector< std::pair<int,int> > block3;
      std::vector< std::pair<int,int> > block4;
      std::vector< std::pair<int,int> > block5;
      std::vector< std::pair<int,int> > block6;
      std::vector< std::pair<int,int> > block7;
      std::vector< std::pair<int,int> > block8;
      std::vector< std::pair<int,int> > block9;

      std::map< std::pair<int, int>, Square > grid;
      std::vector< std::pair<int, int> > unmarked;
      std::vector< std::pair<int,int> > squareToBlock(const int, const int);
      int getMark( const int, const int );
      bool squareEmpty( const int, const int );
      void updateMarked();
      void genBlocks();

};

#endif

