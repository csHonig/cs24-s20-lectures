#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class minStack{

public:
	void push(int item);
	void pop();
	int top();
	bool empty();
   int min();
private:
	stack<int> s;
	stack<int> minSoFar;
};

void minStack::push(int item){
	s.push(item);
   if (minSoFar.empty() || item <=minSoFar.top()){
      minSoFar.push(item);
   }

}
void minStack::pop(){
	assert(!s.empty());
   int t = s.top();
   if(t==minSoFar.top()){
      minSoFar.pop();
   }
   s.pop();

}
int minStack::top(){
	return s.top();

}

int minStack::min(){
   assert(!minSoFar.empty());
      
   return minSoFar.top();
}
bool minStack::empty(){
	return s.empty();
}

int main(){

   minStack ms;
   cout<<"Push 10, 5, 3"<<endl;
   ms.push(10);
   ms.push(5);
   ms.push(3);
   cout<<"Min so far: "<<ms.min()<<endl;
   cout<<"Push 4 2 20"<<endl;
   ms.push(4);
   ms.push(2);
   ms.push(20);
   cout<<"Start emptying the stack"<<endl;
   while(!ms.empty()){
      cout<<"Min: "<<ms.min()<<endl;
      cout<<"Popped: "<<ms.top()<<endl;
      ms.pop();
      
   }


	return 0;
}



