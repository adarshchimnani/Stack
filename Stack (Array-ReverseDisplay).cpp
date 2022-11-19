#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct stack
{
	int stackTop, maxStackSize, stackSize;
	char ask;
	string *list, item;

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
		list=new string [maxStackSize];
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
			cout<<"Please enter any name."<<endl;
			cin.ignore();
			getline(cin,item);
		

			if (!fullStack())
			{
				list[stackTop]=item;
				stackTop++;
			}
				

			else
				cout<<"Stack is full."<<endl;
		
			cout<<"If you want to store more names, enter 'y'."<<endl;
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

		list=new string [maxStackSize];

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

	void reverseDisplay ()
	{
	
		for(int i=0; i<stackTop; i++)
		{
		//	int a=list[i].length();
		//	char *charArray= new char [a+1];
			
		//	strcpy(charArray, list[i].c_str());
		//	for(int l=a; l>=0; l--)
		//	{
				reverse(list[i].begin(), list[i].end());
				cout<<list[i]<<endl;;
		//	}	
			
		//	cout<<endl;
		}
		cout<<endl;
	}

	void menu ()
	{
		ask='y';
		
		int entry;
		{
			while (ask=='y' || ask=='Y')
			{
				cout<<"Welcome."<<endl;
				cout<<"Please enter 1 to Push Stack."<<endl;
				cout<<"Please enter 2 to Pop Stack."<<endl;
				cout<<"Please enter 3 to Display Stack."<<endl;
				cout<<"Please enter 4 to Reverse Display."<<endl;
				cin>>entry;

				if (entry==1)
					push();

				else if (entry==2)
					pop();

				else if (entry==3)
					display();

				else if (entry==4)
					reverseDisplay();
			
				else
					cout<<"Enter the correct entry."<<endl;
		
				cout<<"Do you want to go to the menu?."<<endl;
				cin>>ask;
			}
		}
	}
};

void main ()
{
	stack obj;

	obj.menu();


getch();
}