/*******************************************
 * Created by Shelby Darnell
 * May 16, 2005
 * 
 * base.h
 * File contains generic includes and 
 * useful functions
 * 
 ******************************************/

#ifndef _BASE_H_
#define _BASE_H_

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define UB  10
#define LB -10

using namespace std ;

typedef vector< int > VecInt ;

class Base 
{
public:
	
// String manipulation methods
	static int charStringToInt( char* word ) ;
	static int stringToInt( string word ) ;
	
	static double charStringToDouble( char* word ) ;
	static double stringToDouble( string word ) ;
	
	static string doubleToString( double number ) ;
	static string intToString( int number ) ;

// Number manipulation methods
	static int convertToInt( double n, int length ) ;
	static int decodeBinary( int length, vector<int> binaryRep ) ;
	
	static double convertToDouble( int n, int length ) ;
	
	static vector<int> convertToBinary( int length, int p ) ;
	
// Random number methods	
	static int randInt(int max) ;
	
	static double randDouble() ;
	
// Other methods
	static double clercs( double g1, double g2 ) ;
	static double gasdev(double mult) ;
	static double getCSFit( string cs ) ;
	static double sigmoid( double x ) ;

	static string getDirectory( string source ) ;
} ;

#endif //_BASE_H_
