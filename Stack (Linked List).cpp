#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct node
{
	int info;
	node *link;
};

struct stack
{
	node *stackTop, *newNode, *temp, *current, *last;
	int count, item, entry;
	char ask;

	stack ()
	{
		stackTop=NULL;
	}

	bool empty ()
	{
		return (stackTop==NULL);
	}

	bool full ()
	{
		return false;
	}

	void initialize ()
	{
		while (stackTop!=NULL)
		{
			temp=stackTop;
			stackTop=stackTop->link;
			delete temp;
		}
	}

	void push ()
	{
		ask='y';
		while (ask=='y' || ask=='Y')
		{
			cout<<"Please enter the value in digits."<<endl;
			cin>>item;
		
			newNode = new node;
			newNode->info=item;
			newNode->link=stackTop;
			stackTop=newNode;

			cout<<endl<<"Do you want to enter more values, then press 'y'."<<endl;
			cin>>ask;
		}
	}
	
	void pop ()
	{
		if (stackTop!=NULL)
		{
			temp=stackTop;
			stackTop=stackTop->link;
			delete temp;
		}

		else
			cout<<"Stack is empty."<<endl;
	}

	void copy (stack otherStack)
	{
		if (stackTop!=NULL)
			initialize();

		if (otherStack.stackTop==NULL)
			stackTop=NULL;

		else
		{
			current=otherStack.stackTop;
			stackTop=new node;
			stackTop->info=current->info;
			stackTop->link=NULL;
			last=stackTop;
			current=current->link;

			while (current!=NULL)
			{
				newNode= new node;
				newNode->info = current->info;
				newNode->link=NULL;
				last->link=newNode;
				last=newNode;
				current=current->link;
			}
		}
	}



	
};	

void main ()
{
	stack obj;
	
	

getch();
}