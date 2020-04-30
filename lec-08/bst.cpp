#include <iostream>
using namespace std;
// BST only allows unique keys
class BST{
   public:
      BST(){root = 0;}
      ~BST();
      bool insert(int value); // return false if the value already exists
      bool search(int value) const;
      int min() const;
      int max() const;
      int successor(int value) const;
      bool deleteNode(int value);
      void printInOrder() const;
   private:
      class BSTNode{
         public:
            BSTNode* left;
            BSTNode* right;
            BSTNode* parent;
            int const data;
            BSTNode(const int& d):data{d}{
               left = right = parent =0;
            }
      };
      BSTNode* root;
      void printInOrderHelper(Node* ) const;

};

void BST::printInOrder() const{
   printInOrderHelper(root);
}
void printInOrderHelper(Node* n) const{
   if(!n) return;
   printInOrderHelper(n->left);
   cout<<n->data<<" ";
   printInOrderHelper(n->right);

}

void printPreOrderHelper(Node* n) const{
   if(!n) return; 
   cout<<n->data<<" ";
   printPreOrderHelper(n->left);
   printPreOrderHelper(n->right);

}

int main(){
   return 0;
}