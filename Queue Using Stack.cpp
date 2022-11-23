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

	void display ()
	{
		cout<<endl<<"Remaining items in the queue are: ";
		
		temp=stackTop;
		while (temp!=NULL)
		{
			cout<<temp->info<<" ";
			temp=temp->link;
		}
		cout<<endl;
	}

	
};	


struct queue
{
	stack s1, s2;

	void enqueue(int x)
	{
		s1.push(x);
		cout<<endl<<"The queue has been pushed with: "<<x<<endl;
	}

	void dequeue()
	{
		if(s2.stackTop==NULL)
		{
			for ( int i=1; i<=push_count; i++)
				s2.push(s1.pop());
		}

		int p = s2.pop();
		cout<<endl<<"The queue has been popped of: "<<p<<endl;
	}

	void display()
	{
		s2.display();
	}
};


void main ()
{
	queue q;

	int keys [] = {1, 2, 3, 4, 5};

	for (int key : keys)
	{
		q.enqueue(key);
		push_count++;
	}

	q.dequeue();
	q.dequeue();

	q.display();



_getch();
}

