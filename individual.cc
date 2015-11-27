#include "individual.h"

//-----------------------------------------------

Individual::Individual( int _repSize )
{
	init( _repSize ) ;
}

//-----------------------------------------------

Individual::Individual( VecInt _representation )
{
	representation.clear() ;
	init( _representation ) ;
}	

//-----------------------------------------------

Individual::~Individual()
{
	representation.clear() ;
}

//-----------------------------------------------

void Individual::init( int _repSize )
{
	setRepSize( _repSize ) ;
	initBinaryRep() ;
	setFitness() ;
}

//-----------------------------------------------

void Individual::init( VecInt _representation )
{
	setRepSize( _representation.size() ) ;
	representation = _representation ;
	setFitness() ;
}

//-----------------------------------------------

void Individual::initBinaryRep()
{
	int index = 0 ;
	while ( index < getRepSize() ) 
	{
		if ( rnd.myRandom() < 0.5 )
		{
			representation.push_back( 1 ) ;	
		}
		else
		{
			representation.push_back( 0 ) ;	
		}
		index++ ;
	}
}

//-----------------------------------------------

void Individual::flipMember( int index )
{
	if ( representation.at( index ) == 0 )
	{
		representation[ index ] = 1 ;	
	}
	else
	{
		representation[ index ] = 0 ;
	}
}

//-----------------------------------------------

void Individual::calculateOnes()
{
	int index, sum ;
	
	index = sum = 0 ;
	while ( index < getRepSize() )
	{
		if ( representation.at( index ) == 1 )
		{
			sum++ ;
		}
		index++ ;	
	}
	setOnes( sum ) ;
}

//-----------------------------------------------

string Individual::repToString()
{
	int index = 0 ;
	string result = "" ;

	while ( index < getRepSize() )
	{
		result += Base::intToString( representation.at(index) ) + " " ;
		index++ ;
	}

	return result ; 
}

//-----------------------------------------------

string Individual::toString()
{
	int index = 0 ;
	string result = "" ;

	result += repToString() + ", " + Base::doubleToString( getFitness() ) ; 

	return result ;
}

//-----------------------------------------------

void Individual::setFitness()
{
	double temp = Base::getCSFit( repToString() ) ;
	fitness = ( temp < 0.1 || temp > 100 ) ? 100 : temp ;
	calculateOnes() ;

	if ( fitness != 100 )
		fitness += (double)( getOnes() * 10 ) ;
	else
		fitness = (double) getOnes() * 10 ;
}

//-----------------------------------------------

