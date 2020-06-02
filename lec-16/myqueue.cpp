#include <iostream>
#include <stack>
using namespace std;

class MyQueue{

public:
	void push(int item);
	void pop();
	int front();
	bool empty();
private:
	stack<int> s1;
	stack<int> s2;
};

void MyQueue::push(int item){
	s1.push(item);

}
void MyQueue::pop(){
	if(s2.empty() && !s1.empty()){
		//transfer s1 to s2
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}

	}
	if(!s2.empty())
	   s2.pop();

}
int MyQueue::front(){
	if(s2.empty() && !s1.empty()){
		//transfer s1 to s2
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}

	}
	if(!s2.empty())
	   return s2.top();
	return 0;

}
bool MyQueue::empty(){
	return s1.empty() && s2.empty();
}

int main(){


	return 0;
}



