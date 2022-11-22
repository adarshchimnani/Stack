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

	

	
	
	



	
};	


void main ()
{
	stack obj;
	
	
_getch();
}