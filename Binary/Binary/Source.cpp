#include <iostream>
#include <string>
#include "BINARYTREE.h"
#include <fstream>
#include "Boundcheck.h"
using namespace std;

BinaryTree<string> t;   // create tree. 
string filename; 

void input(string)
{
fstream filest;

	filest.open(filename, ios::in );
	if(!filest)
	   cout<< "error" << endl;
	while( !filest.fail())
	{
		string m;
		string r;
		filest >> m;
		r = test(m);
		t.insertNode(r);
		
	}
}

int main()
{
	cout << "Pleaseinput file path,   \n" ;
	cout << "remmebr to use double \\\\ \n";
	cin >> filename;
	
	/* t.insertNode("4nd stuff");
	t.insertNode("2nd stuff");
	t.insertNode("3rd stuff"); */
	input(filename);
	t.displayInOrder(); //calls private member version since no parameter given  (from smallest to biggest)
	cin.get();
	cin.get();
		return 0;
}

