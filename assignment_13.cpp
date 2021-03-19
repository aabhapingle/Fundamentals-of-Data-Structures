/* A double-ended queue (deque) is a linear list in which additions
and deletions may be made at either end. Obtain a data representation
mapping a deque into a one dimensional array. Write C++ program to
simulate deque with functions to add and delete elements from either
end of the deque. */

// dequeue can be used both as a stack and queue

#include<iostream>
using namespace std;
int maximum = 30;

typedef struct dq{
	int data[30];
	int rear, front;
}dq;

class queue{
public:
	dq q;
	queue(){  // initialisation of the list
		q.rear = -1;
		q.front = -1;
	}

	int empty(){
		if(q.rear == -1){return 1;};
		return 0;
	}

	int full(){
		if((q.rear + 1)% maximum == q.front){return 1;}
			return 0;
	}

	void enqr(int x){		// add an element at the rear
		if(this->empty() == 1){
			q.rear = 0;
			q.front = 0;
			q.data[0] = x;
		}
		else{
			q.rear = (q.rear + 1)%maximum;
			q.data[q.rear] = x;
		}
	}

	void enqf(int x){		// add an element at the front
		if(this->empty() == 1){
			q.rear = 0;
			q.front = 0;
			q.data[0] = x;
		}
		else{
			q.front = (q.front - 1 + maximum)%maximum;
			q.data[q.front] = x;
		}
	}

	int dqf(){		// delete an item from the front end of the queue
		int x;
		x = q.data[q.front];
		if(q.rear == q.front){
			q.rear = -1;
			q.front = -1;
		}
		else{
			q.front = (q.front + 1) % maximum;
		}
		return x;
	}

	int dqr(){		// delete an item from the rear end of the queue
		int x;
		x = q.data[q.rear];
		if(q.rear == q.front){
			q.rear = -1;
			q.front = -1;
		}
		else{
			q.rear = (q.rear-1+maximum) % maximum;
		}
		return x;
	}

	void print(){
		int i;
		i = q.front;
		if(q.front == -1 && q.rear == -1){
			cout<<"Empty queue!"<<endl;
		}
		else{
			while(i != q.rear){
				cout<<q.data[i]<<" ";
				i = (i+1)%maximum;
			}
		}
		cout<<q.data[q.rear];
	}
};

int main(){
	queue obj;

	cout<<"\n";
	cout<<"Doubly Ended Circular Deque  "<<endl;
	cout<<"--------MENU--------"<<endl;
	cout<<" 1.Print elements in the Q\n 2.Insert element at front\n 3.Insert element at rear\n 4.Remove from front\n 5.Remove from rear\n 6.Exit "<<endl;

	int choice = 0;
	cout<<"Enter a choice: ";
	cin >> choice;
	while(choice != 6){
		switch(choice){
		case 1:{
			obj.print();
			break;
		}
		case 2:{
			int num = 0;
			cout<<"Enter the number that you want to insert: ";
			cin>>num;
			obj.enqf(num);
			break;
		}
		case 3:{
			int num = 0;
			cout<<"Enter the number that you want to insert: ";
			cin>>num;
			obj.enqr(num);
			cout<<"Number has been inserted!"<<endl;
			break;
		}
		case 4:{
			cout<<"The number dequed is: "<<obj.dqf()<<endl;
			break;
		}
		case 5:{
			cout<<"The number dequed is: "<<obj.dqr()<<endl;
			break;
		}
		default:{
			cout<<"Please enter a correct option!"<<endl;
		}
		}
		cout<<"\n";
		cout<<"--------MENU--------"<<endl;
		cout<<" 1.Print elements in the Q\n 2.Insert element at front\n 3.Insert element at rear\n 4.Remove from front\n 5.Remove from rear\n 6.Exit "<<endl;
		cout<<"Enter a choice: ";
		cin>>choice;
	}
	return 0;
}
