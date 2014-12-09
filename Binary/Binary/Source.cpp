#include <iostream>
#include <string>
#include "BINARYTREE.h"

using namespace std;

int main()
{
	/* BinaryTree<string> *p; */
	BinaryTree<string> t;   // create tree. 
	t.insertNode("test");
	t.insertNode("2nd stuff");
	t.insertNode("3rd stuff");
	t.displayInOrder(); //calls private member version since no parameter given
	cin.get();
	return 0;
}

