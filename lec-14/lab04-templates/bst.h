// bst.h
// Modified version of lab04 starter code for demo purposes
// changed name of class from IntBST<T> -> BST<T> (Generic, templates)
// Generic? keys (int), any type of key
// shorter list of member functions

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

/*
template <class W>
struct Node {
        W info;
        Node *left, *right, * parent;
        // useful constructor:
        Node(W v) : info(v), left(0), right(0), parent(0) { }
};
Node<int> n1;
*/

template <class T> // BST<T><int> BST<T>1; BST<T><string> BST<T>2: T->type auto x = 9;
class BST {
 public:
    // ctor, dtor, insert and one print method already done in BST<T>.cpp:
    BST();                   // constructor
    ~BST();                  // destructor
    bool insert(T value);     // insert value; return false if duplicate
    bool contains(T value) const;  // true if value is in tree
    void printPreOrder() const; // prints tree data pre-order to cout

 private:

    struct Node {
        T info;
        Node *left, *right, * parent;
        // useful constructor:
        Node(T v) : info(v), left(0), right(0), parent(0) { }
    };

    // just one instance variable (pointer to root node):
    Node* root;

    // recursive utility functions for use by public methods above
    Node* getNodeFor(T value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(T value, Node *n); // note overloading names for simplicity
    void printPreOrder(Node *n) const;
    
};

#include "bst.template"

#endif
