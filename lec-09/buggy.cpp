//linkedlist.cpp
//Diba Mirza

#include <iostream>
#include <vector>
using namespace std;

struct Node{
	Node(int value): data(value), prev(nullptr), next(nullptr){}
	int data;
	Node* prev;
	Node* next;
};

class LinkedList{

public:
	LinkedList():head(0), tail(0){
        //initialization list
        //1. shorthand used when writing constructors
        //2. Only way to initialize const member variables
	}
	~LinkedList(){
		clear();
	}

	LinkedList(LinkedList& other){
		// Implementation that C++ gives you by default
		/*head = other.head;
		tail = other.tail;*/

		// Iterate through the nodes of other
		// In each iteration append a new node to this list

	}

	void operator=(LinkedList& other){
		// Should the implementation
		// of this function be exactly the same
		// as that of a "correct" copy constructor

	}

	void append(int value);
	//Add a integer to the end of the list
	void remove(int value);
	int sum();
	void reverse();
	bool find(int value);
	int count(int value);
	//returns the number of occurences of the value
	int length();
	bool isempty();
	void print();
	void clear(); // Deletes all the nodes in the linked list
	bool isEqual(LinkedList& ll);
	bool isEqual(vector<int>& v);

private:
	Node* head;
	Node* tail;	
};


// Simple test framework
void TESTEQ(LinkedList& l1, LinkedList& l2, string testname){
	cout<<testname<<endl;
	if(l1.isEqual(l2)){ // All the values of the nodes of l1 are equal to l2
		cout<<"PASSED"<<endl;
	}else{
		cout<<"FAILED"<<endl;
	}
}

void TESTEQ(LinkedList& l1, vector<int>& v, string testname){
	cout<<testname<<endl;
	if(l1.isEqual(v)){ // All the values of the nodes of l1 are equal to l2
		cout<<"PASSED"<<endl;
	}else{
		cout<<"FAILED"<<endl;
	}
}

void LinkedList::clear(){
	//free all the nodes of the linked list from heap memory
}
bool LinkedList::isEqual(LinkedList& ll){
	Node* p1 = ll.head;
	Node* p2 = head;
	while( p1 && p2){
		if(p1->data != p2->data){
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return (!p1 && !p2);

}
bool LinkedList::isEqual(vector<int>& v){
	
	vector<int> v2;
	Node* p =head;
	// This code converst the linked list into a vector 
	// A vector isan array that can have a variable size
	while(p){
		v2.push_back(p->data); //append a new element to the vector
		p = p->next;
	}

	return v==v2;// Its convenient to use the vector data type because 


}

void test_append_0(){
	// One test case
	LinkedList ll;
	ll.append(10);
	vector<int> v ={10};
	TESTEQ(ll, v, "test append: add one element to an empty linked list");

}
void test_append_1(){
	// One test case
	LinkedList ll;
	ll.append(10);
	ll.append(50);
	ll.append(30);
	ll.append(80);

	vector<int> v ={10, 50, 30, 80};
	TESTEQ(ll, v, "test append: add 4 elements to an empty linked list");

}

void test_append(){
	test_append_0();
	test_append_1();

}


void LinkedList::append(int value){
	//Empty case
	//Node n1; //Wrong because n1 is on the stack
	         // and n1 will be removed after append
			 // returns
	Node* p = new Node(value);

	if (!head && !tail){
		head = p;
		tail = p;
	} else if(head == tail){
		head->next = p;
		tail = p;
		p->prev = head;
	} else {
		p->prev = tail;
		tail->next = p;
		tail = p;
	}

}

void LinkedList::print(){
	Node* tmp = head;
	while(tmp){
		cout<<tmp->data<< " ";
		tmp = tmp->next;
	}
	cout<<endl;
}

void test_destructor(){
	LinkedList list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.print();
	// With the default destructor this code has a memory leak
}

int main(){

	test_append();
	test_destructor();
	return 0;
}

