#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include "base.h"
#include "randpack.h"

typedef vector< int > VecInt ;

using namespace std ;

class Individual
{
public:
	Individual() {}
	Individual( int ) ;
	Individual( VecInt ) ;
	~Individual() ;

	void init( int ) ;
	void init( VecInt ) ;
	void initBinaryRep() ;
	void flipMember( int ) ;
	void calculateOnes() ;

	string repToString() ;
	string toString() ;

// Setters
	void setRepSize( int _repSize ) { repSize = _repSize ; }
	void setOnes( int _ones ) { ones = _ones ; }
	void setFitness() ;

// Getters
	int getRepSize() { return repSize ; } 
	int getOnes() { return ones ; }
	int getRepAt( int index ) { return representation.at( index ) ; }
	double getFitness() { return fitness ; }

private:
	int repSize,
		ones ;

// Fitness
	double fitness ;

// Vector to hold the genes for the differential
// evolution
	vector< int > representation ;

	RandPack rnd ;
	
} ;

#endif // _INDIVIDUAL_H_
