#include <iostream>
using namespace std;

//linkedlist.cpp
class LinkedList{
   public:
      LinkedList():head{0}, tail{0}{};
      ~LinkedList(){
         cout<<"Destruction"<<endl;
         //Delete all nodes that were allocated heap
         clear();
         //iterate through nodes and delete each one
         //Don't try to delete the linked list object
         // (head, tail)
      }
      LinkedList& operator=(LinkedList& source);
      void append(int value);
      void remove(int value);
      void print();
      void clear(){} //delete all thenodes
   private:
      struct Node{
         int info;
         Node* next;
      };
      Node* head;
      Node* tail;
};

LinkedList& LinkedList::operator=(LinkedList& source){
      //Beware this code is only partially correct!
      //Deep copy of source into the imp
      // A. Use the same code as copy constructor
      // This is also the code for the copy constructor
   
      Node* p = source.head;
      while(p){
         append(p->info);
         p = p->next;
      }
      return *this;//return reference to itself
}

void LinkedList::append(int value){
   Node* p = new Node{value, 0};
   if(!tail){
      //empty linked list
      head = p;
   }else{
      tail->next =p;  
   }
   tail = p;
}

void LinkedList::print(){
   Node* p = head;
   while(p){
      cout<<p->info<<" ";
      p = p->next;
   }
   cout<<endl;
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
   /*LinkedList ll;
   ll.append(10);
   ll.append(20);
   ll.append(30);
   ll.print();
   LinkedList l1;*/
   test_copy_constructor();
   return 0;
}