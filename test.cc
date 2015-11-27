#include "population.h"

using namespace std ;

int main( int argc, char ** argv )
{
	srand( time( NULL ) ) ;
	int index, np, repSize, runs ;

	np = Base::charStringToInt( argv[1] ) ;
	repSize = Base::charStringToInt( argv[2] ) ;
	runs = Base::charStringToInt( argv[3] ) ;

	Population pop( np, repSize ) ;
	index = 0 ;
	while( index < runs )
	{
		pop.update() ;
		cout << "Run " << (index+1) << "\n" << pop.toString() << endl ;
		index++ ;	
	}

	return 0 ;
}


