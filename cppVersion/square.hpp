
#include <string>
#include <set>

#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square {

   public:
      Square();
      Square( const int );
      int getMark();
      bool marked();
      std::set<int>  getPossibilities();
      std::set<int>*  getPossibilitiesRef();
      bool placeMark( const int );
      std::string toString();

   private:
      int mark;
      std::set<int> possibilities;

};

#endif

