#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <stack>
using namespace std;

int main(){
   array<string, 4> fruits 
   {"Orange", "Banana", "Apple", "Papaya"};  // What did we mean by generic?
	array<int, 4> arr1;
   array<float, 10> arr2;
   vector<string> vec; //empty dynamic array
   for(int i =0; i< fruits.size(); i++){
      vec.push_back(fruits[i]);// insert to the end
   }
  
   set<string> bst;
   for (string item: vec){ //C++ 11 range based for loop
      bst.insert(item);
   } // O(NlogN)
   for (auto item: bst){ //traversing a bst 
      cout<<item<<" "; //item is of type string
   } //O(N) 
   //Overall sort: O(NlogN) + O(N)
   // O(NlogN)
   cout<<endl;
   //What is the output of this code?
   /*A. Orange Banana Apple Papaya (same order as array)
     B. Apple Banana Orange Papaya (sorted order)
     Answer is B

   */
   stack<string> s;//last in first out
   s.push("Grapefruit"); //inserts to the top
   cout<<s.top()<<endl; //returns the top element
   s.pop(); //returns void deletes the top element

   for(auto item: bst){
      s.push(item);
   }

   while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
   }


	return 0;
}
