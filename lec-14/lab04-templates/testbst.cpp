// testbst.cpp:
// Modified version of lab04 starter code for demo purposes

#include "bst.h"
#include <iostream>
#include <vector>
using namespace std;

// Make the function generic using templates
template <class item>
void insertIntoBST(BST<item>& b, vector<item>& v)
{
  // insert data to BST<T>1
    for(auto i: v){
        b.insert(i);
    }

}

struct mytype{
  int a;
  string b;
};
int main() {
    vector<int> v1{64, 128, 8, 512, 16, 4};
    BST<int> bst1; 
   // BST<mytype> b3;  // overload the ==, < operators for myttype

    insertIntoBST(bst1, v1);

    cout << " pre-order: ";
    bst1.printPreOrder();
    cout << endl;

    vector<string> v2{"Apple", "Orange", "Banana"};
    BST<string> bst2;
    insertIntoBST(bst2, v2);
    cout << "  pre-order: ";
    bst2.printPreOrder();
    cout << endl;
    return 0;
}
/*
Lab04 extra credit
A. Tried and completed it
B. Tried
C. Haven't started
*/


