#include "randpack.h"

using namespace std ;

//RandPack::RandPack() {}

//-----------------------------------------------

//RandPack::~RandPack() {}

//-----------------------------------------------

void RandPack::myRandomize()
{
	seed = rand() ; //time(NULL);
    myRandom();	
}

//-----------------------------------------------

void RandPack::seed_myRandomize( int _seed )
{
	seed = _seed; 
	myRandom();
}

//-----------------------------------------------

int RandPack::myRandomInt( int modulus )
{
	return (int) ( myRandom() * ( modulus-0.00000001 ) );
}

//-----------------------------------------------

double RandPack::myRandom()
{
	seed = rand() ; 
	int
		a = 16807,
        m = 2147483647,
        q = 127773, /* m div a */
        r = 2836,   /* m mod a */

        lo, hi, test;

	hi = seed / q;
	lo = seed % q;

	test = a * lo - r * hi;

	if (test > 0)
		seed = test;
	else
		seed = test + m;

	return (double) seed/m;
}

//-----------------------------------------------

double RandPack::myRandRange( double v1, double v2 )
{
	double temp;

    if (v2 < v1)
    {
        temp = v2;
        v2 = v1;
        v1 = temp;
    }

    return ((v2-v1) * myRandom() + v1);
}

//-----------------------------------------------
