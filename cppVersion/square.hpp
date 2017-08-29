
#include <set>

#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square {

   public:
      Square( const int );
      int getMark();
      bool marked();
      std::set<int>  getPossibilities();
      bool placeMark( const int );

   private:
      int mark;
      std::set<int> possibilities;

};

#endif

