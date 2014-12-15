#include <iostream>
#include <string>
#include "BINARYTREE.h"
#include <fstream>
#include "Boundcheck.h"
using namespace std;

BinaryTree<string> t;   // create tree. 

void input()
{
fstream filest;

	filest.open("C:\\Users\\Dpnd\\Downloads\\project\\Assignment5\\Article.txt", ios::in );
	if(!filest)
	   cout<< "error" << endl;
	while( !filest.fail())
	{
		string m;
		filest >> m;
		test(m);
		t.insertNode(m);
		
	}
}

int main()
{
	
	
	/* t.insertNode("4nd stuff");
	t.insertNode("2nd stuff");
	t.insertNode("3rd stuff"); */
	input();
	t.displayInOrder(); //calls private member version since no parameter given  (from smallest to biggest)
	cin.get();
		return 0;
}

