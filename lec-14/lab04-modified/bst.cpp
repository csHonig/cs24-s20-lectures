// BST.cpp
// Implements class BST
// YOUR NAME(S), DATE

#include "bst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
BST::BST() : root(0) { }

// destructor deletes all nodes
BST::~BST() {
    clear(root);
}

// recursive helper for destructor
void BST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool BST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool BST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void BST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void BST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void BST::printInOrder() const {
    printInOrder(root);
}
void BST::printInOrder(Node *n) const {
    // IMPLEMENT HERE
}

// prints tree data post-order, with helper
void BST::printPostOrder() const {
    printPostOrder(root);
}

void BST::printPostOrder(Node *n) const {
    // IMPLEMENT HERE
}

// return sum of values in tree
int BST::sum() const {
    return sum(root);
}

// recursive helper for sum
int BST::sum(Node *n) const {
    return 0; // REPLACE THIS NON-SOLUTION
}

// return count of values
int BST::count() const {
    return count(root);
}

// recursive helper for count
int BST::count(Node *n) const {
    return 0; // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
BST::Node* BST::getNodeFor(int value, Node* n) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool BST::contains(int value) const {
    return true; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
BST::Node* BST::getPredecessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int BST::getPredecessor(int value) const{
    return 0; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
BST::Node* BST::getSuccessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int BST::getSuccessor(int value) const{
    return 0; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool BST::remove(int value){
    return false; // REPLACE THIS NON-SOLUTION
}
