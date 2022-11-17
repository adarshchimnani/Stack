#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct stack
{
	int stackTop, maxStackSize, item, stackSize, *list;
	char ask;

	stack ()
	{
		cout<<"Please enter the size of the stack."<<endl;
		cin>>stackSize;

		if (stackSize<=0)
		{
			cout<<"Size must be a positive number."<<endl;
			cout<<"Creating array of 100."<<endl;

			maxStackSize=100;
		}

		else
			maxStackSize=stackSize;

		stackTop=0;
		list=new int [maxStackSize];
	}

	bool emptyStack ()
	{
		return (stackTop==0);
	}

	bool fullStack ()
	{
		return (stackTop==maxStackSize);
	}

	void push()
	{
		ask='y';	
		while (ask=='y' || ask=='Y')
		{
			cout<<"Please enter the value in digits."<<endl;
			cin>>item;

			if (!fullStack())
			{
				list[stackTop]=item;
				stackTop++;
			}
				
			else
				cout<<"Stack is full."<<endl;
		
			cout<<"If you want to store more digits, enter 'y'."<<endl;
			cin>>ask;
		}
	}

	void pop ()
	{
		if (!emptyStack())
			stackTop--;

		else
			cout<<"Empty Stack."<<endl;
	}

	void copy (stack otherStack)
	{
		delete [] list;
		maxStackSize=otherStack.maxStackSize;
		stackTop=otherStack.stackTop;

		list=new int [maxStackSize];

		for (int i=0; i<maxStackSize; i++)
			list[i]=otherStack.list[i];
	}

	void display ()
	{
		if (!emptyStack())
			for (int j=0; j<stackTop; j++)
				cout<<list[j]<<" ";

		cout<<endl;
	}

	
};

void main ()
{
	stack obj;

	


getch();
}