#ifndef _RANDPACK_H_
#define _RANDPACK_H_

#include "base.h"

class RandPack
{
public:
	int seed ;

    void myRandomize() ;
    void seed_myRandomize( int ) ;

    int myRandomInt( int ) ;

    double myRandom() ;
    double myRandRange( double, double ) ;

} ;

#endif //_RANDPACK_H_
