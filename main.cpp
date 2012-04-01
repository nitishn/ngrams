/*
 * main.cpp
 *
 *  Created on: Apr 1, 2012
 *      Author: nitish
 */

// Includes
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "ngram.h"
using namespace std;

// Function prototypes
void parseFile( string );
void generateNGram( int );

// Global constants
vector<ngram> ngrams;	// Container of n-grams
vector<string> buffer;  // Buffer container
int nConstant = 0;		// Constant for any n, n-gram
string space = " ";

int main( int argc, char **argv ) {

	// Set nConstant = to how many n-grams to break into = arg 1
		nConstant = atoi(argv[1]);

	// Set file to parse = arg 2
		string filename = argv[2];

	// Parse input file
	parseFile( filename );

	// Loop over buffer and create n-grams
	for( uint i = 0; i < buffer.size() - nConstant+1; i++) {
		generateNGram( i );
	}


	for( uint i = 0; i < ngrams.size(); i++ ) {
			cout << ngrams[i].getValue() << " " << ngrams[i].getCount() << endl;
		}


	return 0;
}

// Function definitions
void generateNGram( int bufIndex ) {

	// Temporary string to hold the current working n-gram
		string tempGram;
		bool search = false;

	// Loop until nConstant to create temporary n-gram
		for( int j = bufIndex; j < bufIndex + nConstant; j++ ) {

			// Use append function to create the n-gram of size n
				tempGram.append(buffer[j]);
				tempGram.append(space);
		}

	if( bufIndex == 0 ) {
		// If bufIndex is 0, then it's the first n-gram so don't worry about checking for counts
			ngram gram(tempGram);
			ngrams.push_back( gram );
	}

	else {
		ngram gram(tempGram);
		// Check if the n-gram already exists and increment the count if it does
			for( uint i = 0; i < ngrams.size(); i++ ) {
				if( ngrams[i].getValue().compare(tempGram) == 0 ) {
					ngrams[i].addCount();
					search = true;
				}
			}

		// If the n-gram doesn't exist, make a new one and push onto list
			if( !search ) {
				ngrams.push_back( gram );
			}

	}
}

void parseFile( string filename ) {

	// Open file and read
		ifstream fin;
		fin.open( filename.c_str() );
		string temp;

	// Place each word into buffer
		// Prime loop
			fin >> temp;

		// Read file into buffer
			while( fin.good() ) {
				buffer.push_back( temp );
				fin >> temp;
			}

	// Close file
		fin.close();
}
