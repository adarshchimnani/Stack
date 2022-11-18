#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct stack
{
	int stackTop, maxStackSize, item, *list;

	stack (int size)
	{

		if (size<=0)
		{
			cout<<"Size must be a positive number."<<endl;
			cout<<"Creating array of 100."<<endl;

			maxStackSize=100;
		}

		else
			maxStackSize=size;

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

	void push(int x)
	{
		
			if (!fullStack())
			{
				list[stackTop]=x;
				stackTop++;
				cout<<"Stack has been pushed: "<<x<<endl;
			}
				
			else
				cout<<"Stack is full."<<endl;
		
	}

	void pop ()
	{
		if (!emptyStack())
		{
			cout<<"Stack has been popped: "<<list[stackTop-1]<<endl;
			stackTop--;
		}
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



	
};

void main ()
{




	


_getch();
}