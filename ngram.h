/*
 * ngram.h
 *
 *  Created on: Apr 1, 2012
 *      Author: nitish
 */

#ifndef NGRAM_H_
#define NGRAM_H_

#include <string>
using namespace std;

class ngram {
private:
	int count;
	string value;

public:
	ngram( string );
	~ngram();
	int getCount();
	string getValue();
	void addCount();
};

#endif /* NGRAM_H_ */
