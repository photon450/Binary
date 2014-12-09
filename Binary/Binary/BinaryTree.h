#ifndef BINARYTREE_h
#define BINARYTREE_h


#include <iostream>
#include <string>

using namespace std;

template <class T>
class BinaryTree
{
private:
	struct TreeNode
	{
		T word;
		int count;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;

	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(T, TreeNode *&); // t for word or l for adding another count.
	void makeDeletion( TreeNode *&);
    void displayInOrder(TreeNode *) const;   // ......
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;    

public:
	BinaryTree()
	{
		root = nullptr;
	}

	~BinaryTree()
	{ destroySubTree(root); }

	  // Binary Tree ops
	void insertNode(T);               
	bool searchNode(T);
	void remove(T);

	     // so passes root into the function recursively. notice how I overloaded, this one takes no parameters
	void displayInOrder() const
	{
		 displayInOrder(root);  // this refrences the private member version.
	}

    void displayPreOrder() const
	{  displayPreOrder(root); }     // same for this. 

	void displayPostOrder() const
	{     displayPostOrder(root);   }      // also the private member version.

};

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)      // only inserts nodes into tree, not with values.
{
   if (nodePtr == NULL)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->word < nodePtr->word)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

template <class T>
void BinaryTree<T>::insertNode(T item)                                 // creates node with its value
{
   TreeNode *newNode;      // Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->word = item;
   newNode->left = newNode->right = NULL;
   
   // Insert the node.
   insert(root, newNode);
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)    // called by destructor, deletes all nodes in tree, except root?
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
template <class T>
bool BinaryTree<T>::searchNode(T item)   // determines if value exsists in tree node, returns true if exsists
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->word == item)
         return true;
      else if (item < nodePtr->word)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}
template <class T>
void BinaryTree<T>::remove(T item)   // removes the node were node is same as T
{
   deleteNode(item, root);
}

template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)           // finds the node   (makes above work...)
{
   if (item < nodePtr->word)
      deleteNode(item, nodePtr->left);
   else if (item > nodePtr->word)
      deleteNode(item, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)   // this takes a refrence to a pointer so the actual node. node removed and the branch is reatached.
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}


template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const  
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->word << endl;
      displayInOrder(nodePtr->right);
   }
}


template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->word << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->word << endl;
   }
}


#endif // !BinaryTree.H
