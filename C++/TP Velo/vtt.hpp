#ifndef vtt_hpp
#define vtt_hpp

#include <iostream>
#include "velo.hpp"
using namespace std;

class vtt: public velo {
int nbvitesse;
public:
    vtt();
    vtt(int, int, int);
   int getNbVitesse();
   void setNbVitesse(int);
   
};

#endif 