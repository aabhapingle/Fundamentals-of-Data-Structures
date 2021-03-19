#include<iostream>
#include<cmath>
using namespace std;

int seat_no = 1;        // global variable seat number
typedef struct dnode{	// doubly circular linked list node
	int data;
	char s;
	struct dnode *next, *prev;
}dnode;

dnode* insert(dnode *head,int x);
void print(dnode*);

dnode* insert(dnode *head,int x){  // insert a node at the front of the list
	dnode *p;
	p = new dnode;
	p->data = x;
	p->s = 'A';
	p->prev = p->next = NULL;
	if(head == NULL){  // insertion in an empty list
		p->prev = p->next = p;
		return p;
	}
	else{
		p->prev = head->prev;
		p->next = head;
		head->prev->next = p;
		head->prev = p;
		return p;
	}
}

void print(dnode* head){	// print all the elements of the list
	dnode *p;
	p = head;
	do{
		cout<< p->data ;
		cout<<'[' <<p->s << ']'<<" ";
		p = p->next;
	}
	while(p!=head);
}

int func(int num){
	if(num >=1 && num <= 7){
		return 0;
	}
	else if(num >=8 && num <= 14){
		return 1;
	}
	else if(num >=15 && num <= 21){
			return 2;
	}
	else if(num >=22 && num <= 28){
			return 3;
	}
	else if(num >=29 && num <= 35){
			return 4;
	}
	else if(num >=36 && num <= 42){
			return 5;
	}
	else if(num >=43 && num <= 49){
			return 6;
	}
	return -1;
}

int main(){
	cout<<"---------------SCREEN---------------"<<endl;

	dnode* arr[10]; // array for storing the head of the linked lists
	for(int i=0; i<10 ;i++){  // make all the places NULL
		arr[i] = NULL;
	}

	for(int k=0; k<10; k++){  // creating the theatre
		for(int j=0; j<7; j++){  // make one row
			arr[k] = insert(arr[k], seat_no++);
		}
	}

	for(int l=0; l<10; l++){ // display theatre
		print(arr[l]);
		cout<<"\n";
	}

	// menu
	int choice = 0;
	cout<<"\n";
	cout<<"------MENU------"<<endl;
	cout<<" 1.Show theater\n 2.Book tickets\n 3.Cancel tickets\n 4.Exit"<<endl;
	cin>>choice;
	while(choice!=4){
		switch(choice){
		case 1:{
			cout<<"\n";
			cout<<"---------------SCREEN---------------"<<endl;
			for(int l=0; l<10; l++){ // display theatre
				print(arr[l]);
				cout<<"\n";
			}
			break;
		}

		case 2:{
			int seat = 0;
			cout<<"Enter the seat number that you want to book: ";
			cin >> seat;
			int f = func(seat);
			dnode* curr = arr[f];

			if(f == -1){cout<<"Seat number not available !"<<endl;}

			else{
				while(curr->data != seat){
					curr = curr->next;
				}
				if(curr->s == 'A'){
					curr->s = 'B';
					cout<<"Your seat has been booked!"<<endl;
				}
				else{
					cout<<"This seat is not available!"<<endl;
				}
			}
			break;
		}

		case 3:{
			int place = 0;
			cout<<"Enter the seat number that you want to cancel: ";
			cin>>place;
			int d = func(place);
			dnode* curr = arr[d];
			if(d == -1){cout<<"Seat number not available!"<<endl;}
			else{
			while(curr->data != place){
				curr = curr->next;
			}
			if(curr->s == 'B'){
				curr->s = 'A';
				cout<<"Your booking has been cancelled !"<<endl;
			}
			else{
				cout<<"This seat wasn't booked before!"<<endl;
			}
			}
			break;
		}

		default:{
			cout<<"Please enter the correct option!"<<endl;
			break;
		}
		}
		cout<<"\n";
		cout<<"------MENU------"<<endl;
		cout<<" 1.Show theater\n 2.Book tickets\n 3.Cancel tickets\n 4.Exit"<<endl;
		cin>>choice;
	}
	cout<<"Bye bye!"<<endl;

	return 0;
}

