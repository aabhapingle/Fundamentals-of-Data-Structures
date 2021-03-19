/* Write program to implement a priority queue in C++ using an inorder
list to store the items in the queue. Create a class that includes the
data items (which should be template) and the priority (which should be
int). The in order list should contain these objects,
with operator <= overloaded so that the items with highest
priority appear at the beginning of the
list (which will make it relatively easy to retrieve the highest item.)*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
template<class V>
class Node
{
	public:
		V data;
		int priority;
		Node *next;
		Node()
		{
			data=0;
			priority=0;
			next=NULL;
		}

		Node(V a ,int p)
		{
			data=a;
			priority=p;
			next=NULL;
		}
		int operator<=(Node x)    // operator overloading
		{
			if(priority<=x.priority)
			{
				return 1;
			}

				return 0;

		}
};
template<class T>
class PQ
{
	Node<T> *front;
	Node<T>*rear;
	public:
		PQ()
		{
			front=NULL;
			rear=NULL;
		}
		void enquep(T x);
		Node<T> deque();
		void show()
		{
				Node <T>*p=NULL;
				p=front;
				while(p!=NULL)
				{
					cout<<"\n---------------------------------\n";
					cout<<"Element is "<<(T)p->data<<endl;
					cout<<"Priority is "<<p->priority<<endl;

					p=p->next;
				}

		}


};

int main()
{
	char ch;
	char ch1;
	PQ<int>obj1;

	PQ<float>obj2;
	PQ<char>obj3;
	Node<int>a;
	Node<char>b;
	Node<float>c;
	char str[10];
	do
	{
		cout<<"-----------------------MENU------------------\n";
		cout<<"1.Execute for Integers\n2.Execute for Characters\n3.Execute for Float\n0.Exit\n";
		cout<<"---------------------------------------------\n";
		cout<<"\nEnter a choice : ";;
		cin>>ch;
		switch(ch)
		{
			case '1':do
					{
							cout<<"\n-----------------SUB-MENU-------------\n";
						cout<<"1.Add Elements\n2.Delete Elements\n3.Show Elements\n0.back\n";
						cout<<"--------------------------------------\n";
						cout<<"\nEnter choice : ";
						cin>>ch1;
						if(ch1=='1')
						{

							while(1)
							{
								cin.ignore(1);
								cout<<"Enter Element or STOP to exit : ";
								cin.getline(str,9);
								if(strcmp(str,"STOP")==0)
								{
									break;
								}
								else
								{

									obj1.enquep(atoi(str));
								}


							}
						}
						else if(ch1=='2')
						{
							cout<<"\n---------------------------------\n";
							a=obj1.deque();
							cout<<"Element is "<<a.data<<endl;
							cout<<"Priority is "<<a.priority<<endl;

						}
						else if(ch1=='3')
						{
							obj1.show();
						}
						else if(ch1!='0')
						{
							cout<<"Invalid choice\n";
						}

					}while(ch1!='0');
					break;
			case '2':do
					{
						cout<<"\n-----------------SUB-MENU-------------\n";
						cout<<"1.Add Elements\n2.Delete Elements\n3.Show Elements\n0.back\n";
						cout<<"--------------------------------------\n";
						cout<<"\nEnter choice : ";
						cin>>ch1;
						if(ch1=='1')
						{

							while(1)
							{
								cin.ignore(1);
								cout<<"Enter Element or STOP to exit : ";
								cin.getline(str,9);
								if(strcmp(str,"STOP")==0)
								{
									break;
								}
								else
								{

									obj3.enquep(str[0]);
								}


							}
						}
						else if(ch1=='2')
						{
							cout<<"\n---------------------------------\n";
							b=obj3.deque();
							cout<<"Element is "<<b.data<<endl;
							cout<<"Priority is "<<b.priority<<endl;

						}
						else if(ch1=='3')
						{
							obj3.show();
						}
						else if(ch1!='0')
						{
							cout<<"Invlaid choice\n";
						}

					}while(ch1!='0');

					break;
		    case  '3':do
					{
						cout<<"\n-----------------SUB-MENU-------------\n";
						cout<<"1.Add Elements\n2.Delete Elements\n3.Show Elements\n0.back\n";
						cout<<"--------------------------------------\n";
						cout<<"\nEnter choice : ";
						cin>>ch1;
						if(ch1=='1')
						{

							while(1)
							{
								cin.ignore(1);
								cout<<"Enter Element or STOP to exit : ";
								cin.getline(str,9);
								if(strcmp(str,"STOP")==0)
								{
									break;
								}
								else
								{

									obj2.enquep(atof(str));

								}


							}
						}
						else if(ch1=='2')
						{

							cout<<"\n---------------------------------\n";
							c=obj2.deque();
							cout<<"Element is "<<c.data<<endl;
							cout<<"Priority is "<<c.priority<<endl;

						}
						else if(ch1=='3')
						{
							obj2.show();
						}
						else if(ch1!='0')
						{
							cout<<"Invlaid choice\n";
						}

					}while(ch1!='0');

					break;
		    case '0': break;

			default: cout<<"Invalid choice\n";


		}
	}while(ch!='0');
}
template<class T>
void PQ<T>::enquep(T x)
{
	int pt;

	cout<<"Enter Priority                : ";
	cin>>pt;
	cout<<"------------------------------------\n";
	Node<T>*p=NULL;
	Node<T>*q=NULL;
    Node<T>*r=NULL;
	p=new Node<T>(x,pt);
	if(front==NULL)
	{

		front=p;
		rear=p;

	}
	else
	{
		if(front==rear)
		{
			if((p)<=(front))
			{
				front->next=p;
				rear=p;
			}
			else
			{
				p->next=front;
				front=p;
				rear=p->next;
			}
		}
		else
		{
			q=front;
			while(q!=NULL)
			{

				if((q)<=(p))
				{
					break;
				}
				else
				{	r=q;
					q=q->next;
				}

			}
			if(q==front)
			{
				p->next=q;
				front=p;
			}
			else if(q==NULL)
			{
				r->next=p;
				rear=p;
				p->next=NULL;
			}
			else
			{
				p->next=q;
				r->next=p;
			}

		}
	}
}
template<class T>
Node<T> PQ<T>::deque()
{
	Node <T>p;

	if(front==NULL)
	{
		cout<<"Q is Empty......Can't Deque\n";
		return p;
	}
	else
	{
		p.data=(T)front->data;
		p.priority=front->priority;
		if(front==rear)
		{
			front=rear=NULL;
		}
		else
		{
				front=front->next;
		}
		return p;
	}


}
