//class to check for anything that is not a character ie char ' ' btw 65-90 for A -Z , a-z is 97-122, blank 32, period is 46, 0-9 48-57
#ifndef Boundcheck_H
#define Boundcheck_H

#include <iostream>

using namespace std;

string test(string i)
{
   
	const int l = 20;
	 
	/* char b[l] = i; */

	if( i < "0" ||  i == "?" || i == "!" ||  i== "." || i == "," )
		return "punctuation";
	else
		return i;
}

#endif