//linkedlist.cpp
class LinkedList{
   public:
      LinkedList():head{0}, tail{0}{};
      void append(int value);
      void remove(int value);
      void print();
   private:
      struct Node{
         int info;
         Node* next;
      };
      Node* head;
      Node* tail;
};

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

int main(){
   LinkedList ll;
   ll.append(10);
   ll.append(20);
   ll.append(30);
   ll.print();
   return 0;
}