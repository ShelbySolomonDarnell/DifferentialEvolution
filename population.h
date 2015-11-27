#ifndef _POPULATION_H_
#define _POPULATION_H_

#include "individual.h"

typedef vector< int > VecInt ;
typedef vector< Individual > VecInd ;

using namespace std ;

class Population
{
public:
	Population() {}
	Population( int, int ) ;
	~Population() ;

	void init( int, int ) ;
	void update() ;
	double getBestFitness() ;

	Individual getParent( int ) ;
	VecInt selectThree() ;
	string toString() ;

// Setters
	void setSize( int _size ) { size = _size ; }
	void setRepSize( int _repSize ) { repSize = _repSize ; }
// Getters
	int getSize() { return size ; }
	int getRepSize() { return repSize ; }

private:
	int size,
		repSize ;
    Individual offspring ;
	VecInd pop ;
	RandPack rnd ;
} ;

#endif // _POPULATION_H_

