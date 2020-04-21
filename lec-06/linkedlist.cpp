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
  // bool operator==(LinkedList& source);
   void append(int value);
   void remove(int value);
   void print();
   void clear(); //delete all thenodes
   friend ostream& operator<<(ostream& out, const LinkedList& ll); //friend non-member
private:
   struct Node{
      int info;
      Node *next;
   };
   Node *head;
   Node *tail;
   void clearHelper(Node* h);
};
// The << operator has to be a non-member function because the first operand is not of type LinkedList
// cout << ll;
// Non-member function needs to access private member variables/functions of a class: friend functions
ostream& operator<<(ostream& out, const LinkedList& ll){
   //ll.print(); 
   LinkedList::Node* p = ll.head; // head is private so we cannot access it in a non-member function
                      // type Node is private
   while (p){
      out << p->info << " ";
      p = p->next;
   }
   out << endl;
   return out;

}

void LinkedList::clear(){
   // clear all the nodes of the linked list
   clearHelper(head);
   // set head and tail to null
   head = tail = 0;

}

void LinkedList::clearHelper(Node* h){
   if(!h){
      return;
   }
   clearHelper(h->next);
   delete h;
}
// x = y = z; x, y, z are all of type LinkedList
// cout<<ll;
// cout<<l1<<l2<<l3;// cout<<l1 ->operator<<(cout, l1)
// cout<<l2<<l3;
// A. Linked&
// B. ostream&
// C. bool 

//Non-member function (loosely connected with the Class LinkedList)
bool operator==(LinkedList& l1, LinkedList& l2){
   // check if the nodes of l1 are the same as l2
   return false;
}

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
   LinkedList l1, l2, l3;
   /* l2.append(100);
   l2.append(200);
   l3 = l1 + l2; // overload the + operator -> (l1.operator+(l2))
   */
   bool isEqual = (l1 == l2); // overload the == operator
   // If == was implementd as a non member function, then C++ will resolve the expression l1 == l2
   // operator==(l1, l2); A.
   // If == was implementd as a member function, then C++ will resolve the expression l1 == l2
   // l1.operator==(l2); B.
   


   /* Where should we implement the << operator for linked list
   // cout << ll; // cout is a object of type ostream !!  ll is of type LinkedList
   A. Member function (just like = operator):  cout.operator<<(ll); This means modifying ostream!!
   B. Non-member function (is not part of the Linked List class): operator<<(cout, ll);
   C. Both member and non-member work
      l1 == l2; 
   */
   ll.print();
   return 0;
}