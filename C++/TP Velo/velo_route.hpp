#ifndef velo_route_hpp
#define velo_route_hpp

#include <iostream>
#include "velo.hpp"
using namespace std;

class veloRoute: public velo {
bool panier;
public:
    veloRoute();
    veloRoute(int, int, bool);
   void setPanier(bool);
   bool getPanier();
   
};

#endif 