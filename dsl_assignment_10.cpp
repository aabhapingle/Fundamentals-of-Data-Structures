/* Implement C++ program for expression conversion as infix to postfix
and its evaluation using stack based on given conditions:

1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected. */

#include<iostream>
using namespace std;

int maximum = 30;    // maximum number of nodes that the stack can contain

class node{
public:
	char data;
	node* next;
};

class ll{
public:
	node* top;
	int no = 0;   // number of nodes

	ll(){	// constructor
		top = NULL;
		//cout << "stack initialised"<<endl;
	}

	int empty(){
		if(top == NULL){
			return 1;    // empty
		}
		return 0;
	}

	int full(){
		if(no == maximum - 1){
			return 1;    // full
		}
		return 0;
	}

	void push(char a){	// add a new node
		node* temp = new node;
		temp->data = a;
		temp->next = top;
		top = temp;
		no++;
	}

	int pop(){ // remove the topmost element
		no--;
		char number;
		number = top->data;
		node* temp;
		if(top == NULL){   // check for underflow
			cout<<"Stack underflow"<<endl;
		}
		else{
			temp = top;
			top = top->next;
			temp->next = NULL;
			free(temp);	   // release memory
		}
		return number;
	}

	int eval_postfix(char x, int op1, int op2){	// evaluate a postfix expression using a stack
		if(x == '+'){
			return op1+op2;
		}
		else if(x == '-'){
			return op1-op2;
		}
		else if(x == '*'){
			return op1*op2;
		}
		else{
			return op1/op2;
		}
	}

	char top_char(){ // return the character of  the top
		if(top == NULL){
			return '('; // because precedence will be zero
		}
		return top->data;
	}

	int precedence(char x){
		if(x == '('){
			return 0;
		}
		else if(x == '+' || x == '-'){
			return 1;
		}
		else if(x == '*' || x == '/'){
			return 2;
		}
		return 3;
	}

	void infix_to_postfix(char infix[], char postfix[]){
		// cout<<"hi"<<endl;
		char x;
		int i,j;
		char token;
		j = 0;			// traversing the postfix array

		for(i=0; (infix[i]) != '\0'; i++)
		{   // traverse through the postfix expression
			token = infix[i];
			if(isalnum(token)){		// if token is a number or alphabet
				postfix[j++] = token;
				//cout<<"hello"<<endl;
			}
			else{
				if(token == '('){
					push('(');
				}
				else{
					if(token == ')'){	// remove contents from the parathesis ()
						while((x = pop()) != '('){	// note that we are removing '(' but not adding it to the stack
							postfix[j++] = x;
						}
					}
					else{
						while(precedence(token) <= precedence(top_char()) && empty() == 0){
							x = pop();
							postfix[j++] = x;
						}
						push(token);
						// cout<<"done"<<endl;
					}
				}
			}
		}
		while(!empty()){ // if there are any remaining operators in the stack
			x = pop();
			postfix[j++] = x;
		}
		// cout<<"done"<<endl;
		postfix[j] = '\0';
	}
};

int main(){
//	int choice = 0;
//	cout<<"Choose an option:\n 1.Evaluate a postfix expression.\n 2.Convert infix expression to postfix expression.\n 3.exit. "<<endl;
//	cin>>choice;
//	while(choice != 3){
//		switch(choice){
//		case 1:{
//			// evaluation of postfix expression
//							ll s;
//
//							char x;
//							int op1, op2, val;
//
//							cout<< "Enter a postfix expression: "<<endl;
//							while((x = getchar()) != '\n'){
//								if(isdigit(x)){
//									s.push(x-48);
//								}
//								else{
//									op2 = s.pop();
//									op1 = s.pop();
//									val = s.eval_postfix(x, op1, op2);
//									s.push(val);
//								}
//							}
//							val = s.pop();
//							cout<<"The value of the expression is:"<<val<<endl;
//							break;
//
//		}
//
//		case 2:{
//			// infix to postfix conversion
//				ll stack;
//				char infix[30], postfix[30];
//
//				cout<<"Enter an infix expression: "<<endl;
//				gets(infix);  // gets() takes char pointer as parameter // stores character until newline is occurred
//
//				stack.infix_to_postfix(infix, postfix);
//				cout << "The Postfix expression is:"<<postfix;
//
//			break;
//		}
//
//		default:
//			cout<<"Please enter correct option!"<<endl;
//			break;
//
//		}
//		cout<<"Choose an option:\n 1.Evaluate a postfix expression.\n 2.Convert infix expression to postfix expression.\n 3.exit. "<<endl;
//			cin>>choice;
//	}
//
//	cout<<"bye"<<endl;

	// evaluation of postfix expression
	ll s;

	char x;
	int op1, op2, val;

	cout<< "Enter a postfix expression: "<<endl;
	while((x = getchar()) != '\n'){
		if(isdigit(x)){
			s.push(x-48);
		}
		else{
			op2 = s.pop();
			op1 = s.pop();
			val = s.eval_postfix(x, op1, op2);
			s.push(val);
		}
	}
	val = s.pop();
	cout<<"The value of the expression is:"<<val<<endl;

	// infix to postfix conversion
	ll stack;
	char infix[30], postfix[30];

	cout<<"Enter an infix expression: "<<endl;
	gets(infix);  // gets() takes char pointer as parameter // stores character until newline is occurred

	stack.infix_to_postfix(infix, postfix);
	cout << "The Postfix expression is:"<<postfix;

	return 0;
}
