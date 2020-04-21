//linkedlist.cpp
#include <iostream>
using namespace std;
// Operator overloading

class LinkedList{
public:
   LinkedList() : head{0}, tail{0} {};
   ~LinkedList(){
      cout << "Inside destructor" << endl;
      //Delete all nodes that were allocated heap
      clear();
      // iterate through nodes and delete each node
      // Don't try to delete the linked list object
      // (head, tail)
   }
   LinkedList &operator=(LinkedList &source);
   void append(int value);
   void remove(int value);
   void print();
   void clear() {} //delete all thenodes
private:
   struct Node{
      int info;
      Node *next;
   };
   Node *head;
   Node *tail;
};

LinkedList &LinkedList::operator=(LinkedList &source){
   // Beware this code is only partially correct!
   // It doesn't work if the implicit linked list is not empty
   
   // Do a deep copy (similar to copy constructor)
   Node *p = source.head;
   while (p){
      append(p->info);
      p = p->next;
   }
   return *this; //return reference to itself
}

void LinkedList::append(int value)
{
   Node *p = new Node{value, 0};
   if (!tail){
      //empty linked list
      head = p;
   }
   else{
      tail->next = p;
   }
   tail = p;
}

void LinkedList::print()
{
   Node *p = head;
   while (p){
      cout << p->info << " ";
      p = p->next;
   }
   cout << endl;
}

void test_copy_constructor(){
   LinkedList l1;
   l1.append(1);
   l1.append(2);
   LinkedList l2{l1};
   // calls the copy c’tor
   l1.print();
   l2.print();
}

int main(){
   LinkedList ll;
   ll.append(10);
   ll.append(20);
   ll.append(30);
   cout<<ll; // Need to overload the << operator for linked list
   //ll.print();
   return 0;
}