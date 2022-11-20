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
	
	

	



	
};	

void main ()
{
	stack obj;
	
	

getch();
}