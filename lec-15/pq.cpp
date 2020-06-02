#include <iostream>
#include <array>
#include <stack>
#include <queue>

using namespace std;

int main(){
   int arr[]={10, 2, 80};
	priority_queue<int> pq;
	for(int i=0; i < 3; i++)
		pq.push(arr[i]);

	while(!pq.empty()){
		cout<<pq.top()<<endl;
	     pq.pop();
	}
	return 0;

}
