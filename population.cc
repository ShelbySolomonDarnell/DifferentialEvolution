#include "population.h"

//-----------------------------------------------

Population::Population( int _size, int _repSize )
{
	init( _size, _repSize ) ;
}

//-----------------------------------------------

Population::~Population() 
{
	pop.clear() ;
}

//-----------------------------------------------

void Population::init( int _size, int _repSize )
{
	setSize( _size ) ;
	setRepSize( _repSize ) ;

	int index = 0 ;
	while ( index < getSize() )
	{
		pop.push_back( Individual( getRepSize() ) ) ;
		index++ ;
	}
}

//-----------------------------------------------

void Population::update()
{
	int index, 
		indexB, 
		value,
	    thisGene ;
	double p = 0.9,    // p is the crossover constant
		   F = 0.8,    // F is the weighting factor
		   temp ;
	VecInt three, tempOffspring ;
	Individual pA, 
			   pB, 
			   pC ;

	index = 0 ;
	while ( index < getSize() )
	{
		three = selectThree() ;
	// Select 3 Parents
		pA = getParent( three.at(0) ) ;
		pB = getParent( three.at(1) ) ;
		pC = getParent( three.at(2) ) ;
		thisGene = rnd.myRandomInt( getSize() ) ;

		indexB = 0 ;
		while( indexB < getRepSize() )
		{
			value = 0 ;
			if ( rnd.myRandom() < p || thisGene == indexB )
			{
				temp = pA.getRepAt(indexB) + F*( pB.getRepAt(indexB) - pC.getRepAt(indexB) ) ;
				tempOffspring.push_back( (int)temp ) ;
			}
			else
			{
				tempOffspring.push_back( pop.at(index).getRepAt(indexB) ) ;
			}
			indexB++ ;	
		}
		offspring.init( tempOffspring ) ;
		tempOffspring.clear() ;

		pop[index] = ( offspring.getFitness() < pop.at(index).getFitness() ) 
			           ? offspring : pop.at(index) ;

		index++ ;
	}
}

//-----------------------------------------------

double Population::getBestFitness()
{
	int index = 0,
		best = 0 ;

	while ( index < getSize() )
	{
		if ( pop.at(index).getFitness() < pop.at(best).getFitness() )
		{
			best = index ;
		}
		index++ ;
	}	

	return pop.at( best ).getFitness() ;
}

//-----------------------------------------------
/**
 * Allows for mutually exclusive parent selection.
 * This method returns the parents in a vector of
 * integers.
 */

VecInt Population::selectThree()
{
	int temp ;
	VecInt threeParents ;

	threeParents.push_back( rnd.myRandomInt( getSize() ) ) ;

	do
	{
		temp = rnd.myRandomInt( getSize() ) ;
	} while ( temp != threeParents.at( 0 ) ) ;
	threeParents.push_back( temp ) ;
	
	do
	{
		temp = rnd.myRandomInt( getSize() ) ;
	} while ( temp != threeParents.at( 0 ) && temp != threeParents.at( 1 ) ) ;
	threeParents.push_back( temp ) ;

	return threeParents ;
}

//-----------------------------------------------

Individual Population::getParent( int index )
{
	return pop.at( index ) ;
}

//-----------------------------------------------

string Population::toString()
{
	int index = 0 ;
	string result = "" ;
	while( index < getSize() )
	{
		result += Base::intToString( index+1 ) + ", " + pop.at( index ).toString() ;
		result += "\n" ;
		index++ ;
	}
	
	return result ;
}

//-----------------------------------------------

