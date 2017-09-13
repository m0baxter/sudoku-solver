
#include <vector>
#include <utility>
#include <map>

#ifndef SQUARE_HPP
#define SQUARE_HPP

class Puzzle {

   public:
      Puzzle( std::map< std::pair<int, int>, Square > );
      Puzzle( const char* );
      bool markSquare( const int, const int, const int );
      std::vector< std::pair<int, int> > getUnmarked();
      bool columnCheck( const int, const int );
      bool rowCheck( const int, const int );
      bool blockCheck( const int, const int );
      bool markable( const int, const int );
      void printPuzzle();

   private:
      static std::vector< std::pair<int,int> > block1 = { std::make_pair(1,1), std::make_pair(1,2), std::make_pair(1,3),
                                                          std::make_pair(2,1), std::make_pair(2,2), std::make_pair(2,3),
                                                          std::make_pair(3,1), std::make_pair(3,2), std::make_pair(3,3) };
      static std::vector< std::pair<int,int> > block2 = { std::make_pair(1,4), std::make_pair(1,5), std::make_pair(1,6),
                                                          std::make_pair(2,4), std::make_pair(2,5), std::make_pair(2,6),
                                                          std::make_pair(3,4), std::make_pair(3,5), std::make_pair(3,6) };
      static std::vector< std::pair<int,int> > block3 = { std::make_pair(1,7), std::make_pair(1,8), std::make_pair(1,9),
                                                          std::make_pair(2,7), std::make_pair(2,8), std::make_pair(2,9),
                                                          std::make_pair(3,7), std::make_pair(3,8), std::make_pair(3,9) };
      static std::vector< std::pair<int,int> > block4 = { std::make_pair(4,1), std::make_pair(4,2), std::make_pair(4,3),
                                                          std::make_pair(5,1), std::make_pair(5,2), std::make_pair(5,3),
                                                          std::make_pair(6,1), std::make_pair(6,2), std::make_pair(6,3) };
      static std::vector< std::pair<int,int> > block5 = { std::make_pair(4,4), std::make_pair(4,5), std::make_pair(4,6),
                                                          std::make_pair(5,4), std::make_pair(5,5), std::make_pair(5,6),
                                                          std::make_pair(6,4), std::make_pair(6,5), std::make_pair(6,6) };
      static std::vector< std::pair<int,int> > block6 = { std::make_pair(4,7), std::make_pair(4,8), std::make_pair(4,9),
                                                          std::make_pair(5,7), std::make_pair(5,8), std::make_pair(5,9),
                                                          std::make_pair(6,7), std::make_pair(6,8), std::make_pair(6,9) };
      static std::vector< std::pair<int,int> > block7 = { std::make_pair(7,1), std::make_pair(7,2), std::make_pair(7,3),
                                                          std::make_pair(8,1), std::make_pair(8,2), std::make_pair(8,3),
                                                          std::make_pair(9,1), std::make_pair(9,2), std::make_pair(9,3) };
      static std::vector< std::pair<int,int> > block8 = { std::make_pair(7,4), std::make_pair(7,5), std::make_pair(7,6),
                                                          std::make_pair(8,4), std::make_pair(8,5), std::make_pair(8,6),
                                                          std::make_pair(9,4), std::make_pair(9,5), std::make_pair(9,6) };
      static std::vector< std::pair<int,int> > block9 = { std::make_pair(7,7), std::make_pair(7,8), std::make_pair(7,9),
                                                          std::make_pair(8,7), std::make_pair(8,8), std::make_pair(8,9),
                                                          std::make_pair(9,7), std::make_pair(9,8), std::make_pair(9,9) };
      std::map< std::pair<int, int>, Square > grid;
      std::vector< std::pair<int, int> > unmarked;
      std::vector< std::pair<int,int> > squareToBlock(const int, const int);
      int getMark( const int, const int );
      bool squareEmpty( const int, const int );
      void updateMarked();

};

#endif

