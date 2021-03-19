// assignment 8 b

// Problem Statement

/*Second year Computer Engineering class,
 * set A of students like Vanilla Ice-cream and
 * set B of students like butterscotch ice-cream.
 * Write C++ program to store two sets using linked list.
 * compute and display-
 * a) Set of students who like both vanilla and butterscotch
 * b) Set of students who like either vanilla or butterscotch or not both
 * c) Number of students who like neither vanilla nor butterscotch */

#include<iostream>
using namespace std;

class node{
public:
	char name;
	node* next;
};

class Linked_list{
public:
	node* head;

public:
	Linked_list(){
		head = NULL;
	}

	Linked_list(char some_name){
		head->name = some_name;
		head = NULL;
	}

	// add node at the beginning
	void addnode(char n){
		node *t = NULL;
		t = new node;
		t->name = n;
		t->next = head;
		head = t;
		// cout<<"head shifted"<<endl;
	}

	// display names of all the students in the ll
	void disp_elements(){
		node *curr = head;
		cout<<"List of students: ";
		cout<<"[ ";
		while(curr != NULL){
			cout << curr->name<<" ";
			curr = curr->next;
		}
		cout<<"]";
		cout<<endl;
	}

	// find the intersection of two linked lists

	void intersection(Linked_list ll_1, Linked_list ll_2){

		node *curr1 = ll_1.head;

		while(curr1!= NULL){
			node *curr2 = ll_2.head;
			while(curr2 != NULL){
				if(curr1->name == curr2->name){
					addnode(curr2->name);
					// break;
				}
				curr2 = curr2->next;
			}
			curr1 = curr1->next;
		}
	}

	void difference(Linked_list ll1, Linked_list ll2){
		// perform ll1 - ll2

		node *curr1 = ll1.head;

		// don't like both flavors
		while(curr1 != NULL){
			node *curr2 = ll2.head;
			int count = 0;

			while(curr2 != NULL){
				if(curr1->name == curr2->name){
					count++;
				}
				curr2 = curr2->next;
			}
			if(count == 0){
				addnode(curr1->name);
			}
			curr1 = curr1->next;
		}
	}

	void merge(Linked_list ll1, Linked_list ll2 ){
		node *curr1 = ll1.head;

		while(curr1 != NULL){
			node *curr2 = ll2.head;
			int count = 0;
			while(curr2 != NULL){
				if(curr2->name == curr1->name){
					count ++;
				}
				curr2 = curr2->next;
			}
			if (count == 0){
				addnode(curr2->name);
			}
			curr1 = curr1->next;
		}

		node *curr3 = ll1.head;

		while(curr3 != NULL){
			addnode(curr3 -> name);
			curr3 = curr3 -> next;
		}
	}
};

int main(){

	Linked_list A;   // Students from set A like vanilla

	Linked_list B;   // Students from set B like butterscotch

	Linked_list N;   // Students from set N do not like any of these flavors

	Linked_list C;   // linked list containing the students common to both the lists
	C.intersection(A, B);

	Linked_list D1; // Linked list containing the students who like van or butter but not both
	//D1.difference(A, C);

	Linked_list D2;
	//D2.difference(B, C);

	Linked_list M; // merge these two lists
	//M.merge(D1, D2);

	// these linked lists have to be defined out of the switch case

	int choice = 0;
	cout << "Choose an option:"<<endl;
	cout << "------------------------------------------------------"<<endl;
	cout << " 1.Add students who like vanilla.\n 2.Add students who like butterscotch.\n 3.Add students who don't like either of these.\n 4.Display Student List.\n 5.Students who like both flavors.\n 6.Students who like vanilla or butterscotch or not both. \n 7.Exit"<<endl;
	cout << "------------------------------------------------------"<<endl;
	cin >> choice;

	while(choice != 7){

		switch(choice){
		case 1:{
			cout<<"Enter name of the student who likes vanilla:";
			char van;
			cin >> van;

			A.addnode(van);
			break;
		}

		case 2:{
			char but;
			cout<<"Enter name of the student who likes butterscotch:";
			cin>>but;

			B.addnode(but);
			break;
		}

		case 3:{
			char no;
			cout<<"Enter the name of the student who doesn't like either of these: ";
			cin >> no;

			N.addnode(no);
			break;
		}

		case 4:{
			cout<<"-----Students who like vanilla-----"<<endl;
			A.disp_elements();

			cout<<"-----Students who like butterscotch-----"<<endl;
			B.disp_elements();

			cout<<"-----Students don't like either-----"<<endl;
			N.disp_elements();

			break;
		}

		case 5:{
			cout<<"-----Students who like both flavours-----"<<endl;
			C.intersection(A, B);
			C.disp_elements();
			break;
		}

		case 6:{
			cout<<"Set of students who like either vanilla or butterscotch or not both."<<endl;
			//C.intersection(A, B);

			D1.difference(A, C);
			D2.difference(B, C);

			D1.disp_elements();
			D2.disp_elements();

			N.disp_elements();
			//M.merge(D1, D2);

			//M.disp_elements();
			break;
		}

		default:{
			cout<<"Please enter valid option!";
			break;
		}
		}

		cout << "Choose one option:"<<endl;
		cout << "------------------------------------------------------"<<endl;
		cout << " 1.Add students who like vanilla.\n 2.Add students who like butterscotch.\n 3.Add students who don't like either of these.\n 4.Display Student List.\n 5.Students who like both flavors.\n 6.Students who like vanilla or butterscotch or not both. \n 7.Exit"<<endl;
		cout << "------------------------------------------------------"<<endl;
		cin >> choice;
	}

	cout<<"BYE BYE";
	return 0;
}

