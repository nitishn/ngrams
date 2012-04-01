/*
 * ngram.cpp
 *
 *  Created on: Apr 1, 2012
 *      Author: nitish
 */

#include "ngram.h"

ngram::ngram( string val ) {

	// Count keeps track of number of instances this ngram shows up
	count = 1;

	// Value is the ngram string
	value = val;
}

ngram::~ngram() {
	// TODO Auto-generated destructor stub
}

int ngram::getCount() {
	return count;
}

string ngram::getValue() {
	return value;
}

void ngram::addCount() {
	count++;
}
