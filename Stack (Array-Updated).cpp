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

	
	
};

void main ()
{




	


_getch();
}