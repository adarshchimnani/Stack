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


	



	
};	

void main ()
{
	stack obj;
	
	

getch();
}