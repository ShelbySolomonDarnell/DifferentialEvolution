#include "base.h"

using namespace std ;

/**
 * String manipulation methods
 */

	//-----------------------------------------------
	
	// Converts a character string into an integer
	int Base::charStringToInt( char* word )
	{
		int result ; 
		stringstream temp ;
	
		temp << word ;
		temp >> result ;
	
		return result ;
	}
	
	//-----------------------------------------------
	
	// Converts a string into an integer
	int Base::stringToInt( string word )
	{
		int result ; 
		stringstream temp ;
	
		temp << word ;
		temp >> result ;
	
		return result ;
	}
	
	//-----------------------------------------------
	
	// Converts a character string into a double
	double Base::charStringToDouble( char* word )
	{
		double result ; 
		stringstream temp ;
	
		temp << word ;
		temp >> result ;
	
		return result ;
	}
	
	//-----------------------------------------------
	
	double Base::stringToDouble( string word )
	{
		double result ; 
		stringstream temp ;
	
		temp << word ;
		temp >> result ;
	
		return result ;
	}
	
	//-----------------------------------------------
	
	// Converts a double into a string
	string Base::doubleToString( double number ) 
	{
		string result ;
		stringstream temp ;
	
		temp << number ;
		temp >> result ;
	
		return result ;
	}
	
	//-----------------------------------------------
	
	// Converts an integer into a string
	string Base::intToString( int number ) 
	{
		string result ;
		stringstream temp ;
	
		temp << number ;
		temp >> result ;
	
		return result ;
	}
	
/**
 * Number Manipulation Methods
 */
 
 	//-----------------------------------------------
 	
	int Base::convertToInt ( double n, int length )
	{
	    return ( int )( ( ( n - LB ) * ( pow( 2.0, length ) - 1 ) ) / ( UB - LB ) );
	}
	
	//-----------------------------------------------
	
	/**
	 * Method works correctly.  
	 * 
	 * It take the length of a binary representation 
	 * and obtains its integer value.
	 */
	int Base::decodeBinary( int length, VecInt binaryRep )
	{
		int up, down, phenotype ;
		
		phenotype = up = 0 ;		
		down = length - 1 ;
		while ( up < length )
		{
			if ( binaryRep.at( up ) == 1 )
			{
				phenotype +=  (int) pow( 2.0, down ) ;
			}
	
			up++ ;
			down-- ;
		}			
		return phenotype ;
	}
	
	//-----------------------------------------------
	
	double Base::convertToDouble ( int n, int length )
	{
	    return ( ( ( UB - LB ) * n ) / ( pow( 2.0, length ) - 1 ) + LB );
	}
	
	//-----------------------------------------------	
	
	VecInt Base::convertToBinary( int length, int p ) 
	{
		int index = length - 1 ;
		int subtractor ;
		VecInt reps ;
	
		while ( index > -1 ) 
		{
			subtractor = ( int )pow( (double)2, index ) ;	
			if ( p >= subtractor )
			{
				p -= subtractor ;
				reps.push_back( 1 ) ;
			}
			else
			{
				reps.push_back( 0 ) ;
			}
			index-- ;
		}
		return reps ;
	}
	
/**
 * Random Number Methods
 */
	//-----------------------------------------------
	
	// Function to derive a random integer
	int Base::randInt(int max)
	{
	    return (int)((double)max * rand() / ( RAND_MAX + 1.0 )) ;
	}
                                                                                
	//-----------------------------------------------
                                                                                
	// Function to derive a random doubleing point number
	double Base::randDouble()
	{
	    return (double) (rand()/(RAND_MAX+1.0)) ;
	}
	
/**
 * Other methods
 */
 
 	//-----------------------------------------------

	/**
	 *  Function to help move a particle in PSO
	 * 		The inputs that the function takes are phi 1 
	 * 		and phi 2 which denote social and cognitive
	 * 		awareness.
	 */
	double Base::clercs( double g1, double g2 )
	{
		double k, gam, gam4, gsr, gabs;
	
		gam = g1 + g2;
		gam4 = gam * 4;
		gsr = sqrt( pow( gam, 2 ) );
		gabs = fabs( 2 - gam - gsr - gam4 );
		k = 2 / gabs;
	
		return k;
	}

	//-----------------------------------------------

	double Base::gasdev(double mult)
	{
	    static int iset=0;
	    static double gset;
	    double fac, rsq, v1, v2;//, idum;
	                                                                                
	                                                                                
	    if ( iset == 0 )
	    {                         // We don't have an extra deviate handy so,
	        do {
	            v1=2.0 * randDouble( ) - 1.0;   // pick two uniform #'s in the square
	            v2=2.0 * randDouble( ) - 1.0;   // extending from -1 to +1 in each
	            rsq = ( v1*v1 ) + ( v2*v2 );     // direction, see if they are in the unit circle,
	        } while( rsq >= 1.0 || rsq == 0.0 ); // and if they are not, try again.
	                                                                                
	        fac=sqrt( -2.0*log( rsq )/rsq );
	                                            // Now make the Box-Muller transformation to
	                                            // get 2 normal deviates.
	                                            // Return one and save the other for next time.
	        gset=v1*fac;                        // Set flag.
	        iset=1;
	        return v2*fac*mult;
	    }
	    else
	    {
	                               // We have an extra deviate handy.
	        iset=0;                             // so unset the flag.
	        return gset*mult;                       // and return it.
	    }
	}
	
	//-----------------------------------------------
	
	/** 
	 * Runs pedsim to get the fitness of the 
	 * candidate solution
	 */
	double Base::getCSFit( string cs )
	{
		string configFile, pedsimExecute, fitnessFile ; 
	
		configFile = getDirectory( "pedsim" ) + "config2.in" ;
		pedsimExecute = getDirectory( "pedsim" ) + "pedsim" ;
		fitnessFile = getDirectory( "pedsim" ) + "fit.in" ;
	
		// Write the candidate solution to file so 
		// that pedsim can read it
		double fitness ;
		ofstream out( configFile.c_str() ) ; 
		out << cs << endl ;
		out.close() ;
	
		system( pedsimExecute.c_str() ) ;
		//cout << "Pedsim execute " << pedsimExecute << endl ;
	
		// Read the candidate solution fitness from the 
		// file written by pedsim
		ifstream in( fitnessFile.c_str() ) ; 
		in >> fitness ;
		if ( fitness == 0 ) { fitness = 100 ; }
		in.close() ;

		//cout << "Fitness from the base.cc file " << fitness << endl ;
	
		return fitness ;
	}
	
	//-----------------------------------------------
 	
	double Base::sigmoid( double x )
	{
		double result, temp ;
		temp = 1 - exp( -x ) ;
		result = 1 / temp ;
		return result ;
	}
	
	//-----------------------------------------------

	string Base::getDirectory( string source )
	{
		string result ;
		if ( source == "pedsim" )
		{
			ifstream inFile( "data/pedsimDirectory.dat", ios::in ) ;
			inFile >> result ;
		}
		else 
		{
			ifstream inFile( "data/particle_swarm.dat", ios::in ) ;
			inFile >> result ;
		}
		return result ;
	}
	
	//-----------------------------------------------

