#include <iostream>
#include <array>
#include <stack>
#include <queue>
using namespace std;

int main(){
   array<string, 4> fruits {"Orange", "Banana", "Apple", "Papaya"}; 
   stack<string> s; //last in first out
   for(auto item: fruits){
      s.push(item); //insert
   }
   cout<<"Printing out elements in the stack:"<<endl;
   while(!s.empty()){
      cout<<s.top()<<" "; //check the top element on the stack
      s.pop(); //delete the top element on the stack
   }
   cout<<endl;
   // Heaps (min-Heap or max-Heap) or priority queue (by default max heap)
   // push() : insert into pq   O(log N)
   // top() : returns the maximum (or min) key: O(1)
   // pop() : deletes the maximum (or min) key: O(log N)
   // empty(): true if empty O(1)
   //array<string, 4> fruits {"Orange", "Banana", "Apple", "Papaya"};
   priority_queue<string> pq;
   for(auto item: fruits){
      pq.push(item); //insert
   }
   cout<<"\nPrinting out elements in the pq:"<<endl;
   while(!pq.empty()){
      cout<<pq.top()<<" "; //check the top element on the stack
      pq.pop(); //delete the top element on the stack
   }
   cout<<endl;
   // Elements are sorted in reverse order
   // Sorting
   // Compression algorithms (Huffman code)
   // Shortest path on graph (Djakstra)




	return 0;
}
