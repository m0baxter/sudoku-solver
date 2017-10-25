
#include <map>
#include <vector>

#ifndef KEYSNVALS_HPP
#define KEYSNVALS_HPP

template< typename keyType, typename valType >
std::vector<keyType> getKeys( std::map<keyType, valType> const& map ) {

   std::vector<keyType> keys;

   for (auto const& element : map) {
      keys.push_back( element.first );
   }

   return keys;
}


template< typename keyType, typename valType >
std::vector<valType> getValues( std::map<keyType, valType> const& map ) {

   std::vector<valType> values;

   for (auto const& element : map) {
      values.push_back( element.second );
   }

   return values;
}

#endif
