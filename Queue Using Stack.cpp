#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int push_count=0;

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

	int push (int x)
	{
		newNode = new node;
		newNode->info=x;
		newNode->link=stackTop;
		stackTop=newNode;
		count++;
		return x;
	//	cout<<endl<<"Queue has been pushed with: "<<x<<endl;
	}
	
	int pop ()
	{
		if (stackTop!=NULL)
		{
			int d=stackTop->info;
		//	cout<<endl<<"Queue has been popped of: "<<stackTop->info<<endl;
			temp=stackTop;
			stackTop=stackTop->link;
			delete temp;
			count--;
			return d;
		}

		else
		{
			cout<<"Queue is empty."<<endl;
			return 0;
		}
	
	}

	int peek ()
	{
		if(!emptyStack())
			return stackTop->info;

		else
			return 0;
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
	



_getch();
}

