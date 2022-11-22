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
	
	



	
};	


void main ()
{
	stack obj;
	
	
_getch();
}