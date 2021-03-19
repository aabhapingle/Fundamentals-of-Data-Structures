/* In any language program mostly syntax error occurs due to
unbalancing delimiter such as (),{},[]. Write C++ program using stack
to check whether given expression is well parenthesized or not. */

#include<iostream>
using namespace std;

int maximum = 30;

typedef struct stack{
	char data[30];
	int top;
}stack;

void init(stack*);        // initialize the stack
int empty(stack*);		  // check whether empty
int full(stack*);		  // check whether full
char pop(stack*);		  // remove top element
void push(stack* ,char);  // add element to the top

int main(){
	stack s;
	init(&s);

	string str = "[[({})";
	cout<<"******************"<<endl;
	cout<<"Enter a sentence: ";
	getline(cin, str);   // string input using getline
	int n=0;
	for(int i=0; i<str.length(); i++){
		if(str.at(i) == '(' || str.at(i) == '[' || str.at(i) == '{' ){     // opening brackets
			push(&s, str.at(i));

		}
		else if(str.at(i) == ']' || str.at(i) == ')' || str.at(i) == '}'){ // closing brackets
			char p = pop(&s);
			if((str.at(i) == ']' && p == '[') ||(str.at(i) == ')' && p == '(')||(str.at(i) == '}' && p == '{') ){

			}
			else{
				n=1;
			}
		}
	}

	if(n==1){
		cout<<"The string isn't well parenthesized.";
	}
	else{
		int check = empty(&s);
			if(check == 1){
				cout<<"The string is well paranthesized.";
			}else{
				cout<<"The string isn't well paranthesized.";
			}
	}

	return 0;
}

void init(stack* s){
	s->top = -1;
}

int empty(stack* s){
	if(s->top == -1){
		return 1;  // empty
	}
	return 0;  	   // non empty
}

int full(stack* s){
	if(s->top == maximum - 1){
		return 1;   // full
	}
	return 0;       // not full
}

void push(stack* s ,char b){
	s->top = s->top + 1;
	s->data[s->top] = b;
}

char pop(stack* s){
	char b;
	b = s->data[s->top];
	s->top = s->top -1;
	return b;
}
