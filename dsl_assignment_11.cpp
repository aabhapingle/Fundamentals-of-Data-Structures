/* Queues are frequently used in computer programming, and a typical example
is the creation of a job queue by an operating system. If the operating system
does not use priorities, then the jobs are processed in the order they enter
the system. Write C++ program for simulating job queue. Write functions to add
job and delete job from queue. */

#include<iostream>
using namespace std;

const int maximum = 50;

typedef struct qnode{
	int r,f;
	int data[maximum];
}qnode;

class Queue{
public:
	qnode q;
	Queue(){    // initialise empty queue
		q.r = -1;
		q.f = -1;
	}
	int empty(){
		if(q.r == -1){
			return 1; // is empty
		}
		return 0;
	}
	int full(){
		if(q.r == maximum-1){
			return 1; // is full
		}
		return 0;
	}
	void enque(int x){ // add element to the end
		if(q.r ==-1){// empty queue
			q.r = q.f = 0;
			q.data[q.r] = x;
		}
		else{
			q.r = q.r + 1;
			q.data[q.r] = x;
		}
	}
	int dequeue(){
		int x;
		x = q.data[q.f];
		if(q.r == q.f){
			q.f = -1;
			q.r = -1;
			cout<<"Queue Empty!"<<endl;
		}
		else{
			q.f = q.f + 1;
		}
		return x;
	}
	void print(){
		if(this->empty() != 1){
			cout<<"Elements in the queue:"<<endl;
			for(int i = q.f; i <= q.r;i++){
				cout<<q.data[i]<<" ";
			}
		}
		else{
			cout<<"The queue is empty!"<<endl;
		}
	}
};

int main(){
	Queue obj1;
//	int x;
//	cout<<"Enter 5 elements:"<<endl;
//	for(int i=0; i<=5;i++){
//		cout<<"Enter:"<<endl;
//		cin>>x;
//		if(obj1.full() != 1){
//			obj1.enque(x);
//		}
//		else{
//			cout<<"Sorry, queue is full !"<<endl;
//			exit(0);
//		}
//
//	}
//	obj1.print();
//	cout<<"removed"<<endl;
//	cout<<obj1.dequeue()<<endl;

	int choice = 0;
	cout<<"\n";
	cout<<"------MENU------"<<endl;
	cout<<" 1.Display Queue\n 2.Add Job\n 3.Delete job\n 4.Exit"<<endl;
	cin>>choice;

	while(choice != 4){
		switch(choice){
		case 1:{
			obj1.print();
			break;
		}
		case 2:{
			int num = 0;
			cout<<"Enter a number that you wish to add:";
			cin>>num;
			obj1.enque(num);
			cout<<"NUmber added!"<<endl;
			break;
		}
		case 3:{
			obj1.dequeue();
			cout<<"Dequeue performed!"<<endl;
			break;
		}
		default:{
			break;
		}
		}
		cout<<"\n";
		cout<<"------MENU------"<<endl;
		cout<<" 1.Display Queue\n 2.Add Job\n 3.Delete job\n 4.Exit"<<endl;
		cin>>choice;

	}
	cout<<"Bye Bye!";
	return 0;
}
