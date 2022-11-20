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

	void menu ()
	{
		ask='y';
	
		while (ask=='y' || ask=='Y')
		{
			cout<<"Welcome."<<endl;
			cout<<"Please enter 1 to Push Stack."<<endl;
			cout<<"Please enter 2 to Pop Stack."<<endl;
			cout<<"Please enter 3 to Display Stack."<<endl;

			cin>>entry;

			if (entry==1)
				push();

			else if (entry==2)
				pop();

			else if (entry==3)
				display();

			else
				cout<<"Please entry the correct entry."<<endl;

			cout<<"Do you want to enter to the menu, enter 'y'."<<endl;
			cin>>ask;
		}
	}
};	

void main ()
{
	stack obj;
	
	

getch();
}