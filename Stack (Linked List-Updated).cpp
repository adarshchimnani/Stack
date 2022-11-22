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
		count=0;
	}

	bool emptyStack ()
	{
		return (stackTop==NULL);
	}

	bool fullStack ()
	{
		return false;
	}

	void initialize () //Omitting list
	{
		while (stackTop!=NULL)
		{
			temp=stackTop;
			stackTop=stackTop->link;
			delete temp;
		}
	}

	void push (int x)
	{
		newNode = new node;
		newNode->info=x;
		newNode->link=stackTop;
		stackTop=newNode;
		count++;
		cout<<endl<<"Stack has been pushed with: "<<x<<endl;
	}
	
	void pop ()
	{
		if (stackTop!=NULL)
		{
			cout<<endl<<"Stack has been popped of: "<<stackTop->info<<endl;
			temp=stackTop;
			stackTop=stackTop->link;
			delete temp;
			count--;
		}

		else
		{
			cout<<"Stack is empty."<<endl;
		}
	
	}

	void peek ()
	{
		if(!emptyStack())
			cout<<endl<<"The Top element of the stack is: "<<stackTop->info<<endl;

		else
			cout<<endl<<"Stack is Empty."<<endl;
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

	void display ()
	{
		temp=stackTop;

		while (temp!=NULL)
		{
			cout<<temp->info<<" ";
			temp=temp->link;
		}
		cout<<endl;
	}

	
};	


void main ()
{
	stack obj;
	
	obj.push(1);
	obj.push(2);
	obj.push(3);

	obj.peek();

	obj.pop();
	obj.pop();
	obj.pop();

	if(obj.emptyStack())
		cout<<"Stack is empty."<<endl;

	else
		cout<<"Stack is not empty."<<endl;

_getch();
}