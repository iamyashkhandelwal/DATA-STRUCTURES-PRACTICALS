/*
	Implement Circular Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list
*/
#include<iostream>
using namespace std;

template <class t>
class node
{
	public:
		t data;
		node *next;
};

template <class t>
class  clist
{
	int n;
	node<t> *first,*last;
	public:
		clist()	{
			first=NULL;
		}
	void create();
	int count();
	void insertX();
	void insertAfterX();
	int search();
	void reverse();
	void display(); 
	void deleteX();
	void deleteAfterX();
};

//create function
template <class t>
void clist<t>:: create()
{
	node<t> *current,*temp;
	cout<<"\nHow many nodes you want to enter in linked list : ";
	cin>>n;
	if(n>0)
	{
		if(first==NULL)
		{
			first=new node<t>;
			cout<<"\nEnter data for node #1 : ";
			cin>>first->data;
			first->next=first;
		}
		current=first;
		for(int i=1;i<n;i++)
		{
			cout<<"\nEnter data for node #" << i+1 << " : ";
			temp=new node<t>;
			cin>>temp->data;
			temp->next=current->next;
			current->next=temp;
			current=current->next;
		}
		last=current;
	}
}

//count the list
template <class t>
int clist<t>:: count()
{
	node<t> *current;
	current=first;
	int c=0;
	while(current->next!=first)
	{
		c++;
		current=current->next;
	}
	c++;
	return c;
}

//insert function
template <class t>
void clist<t>:: insertX()
{
	int n=count()+1;
		node<t> *current,*temp;
		current=first;
		temp=new node<t>;
		cout<<"\nEnter data : ";
		cin>>temp->data;
		temp->next=NULL;
		if(n==1)
		{
			temp->next=first;
			first=temp;
			last->next=first;
		}
		else
		{
			for(int i=1;i<n-1;i++)
				current=current->next;
			temp->next=current->next;
			current->next=temp;
		}
}
template <class t>
void clist<t>:: insertAfterX()
{
	cout<<"\nEnter the position of insertion : ";
	cin>>n;
	int b=count();
	if(n<=b+1)
	{
		node<t> *current,*temp;
		current=first;
		temp=new node<t>;
		cout<<"\nEnter data : ";
		cin>>temp->data;
		temp->next=NULL;
		if(n==1)
		{
			temp->next=first;
			first=temp;
			last->next=first;
		}
		else
		{
			for(int i=1;i<n-1;i++)
			current=current->next;
			temp->next=current->next;
			current->next=temp;
		}
	}
	else
		cout<<"\nCan't be inserted";
}

//deletion now vomes
template <class t>
int clist<t>:: search()
{
	int flag=0;
	cout<<"\nEnter data to be searched : ";
	cin>>n;
	node<t> *current,*lp,*temp;
	int b=count();
	current=first;
	int i;
	for(i=1;i<=b;i++)
	{
		if(current->data==n)
		{
			flag=1;
			break;
		}
		lp=current;
		current=current->next;
	}
	if(flag==1)
	{
		cout<<"\nData found at index "<<i;
		return i;
	}
	else
		cout<<"\nData not found : ";
	return -1;
}

//reverse function
template <class t>
void clist<t>:: reverse()
{
	node<t> *a,*b,*temp;
	a=first;
	b=a->next;
	temp=b->next;
	a->next=NULL;
	while(temp!=first)
	{
		b->next=a;
		a=b;
		b=temp;
		temp=temp->next;
	}
	b->next=a;
	first->next=b;
	first=first->next;
}

//display
template <class t>
void clist<t>:: display()
{
	node<t> *current;
	current=first;
	while(current->next!=first)
	{
		cout<<current->data<<" -> ";
		current=current->next;
	}
	cout<<current->data<<" \n";
}

//deletion
template <class t>
void clist<t>:: deleteX()
{
	int pos=search();
	node<t> *t2=first;
	node<t> *p;
	int temp=count();
	if(temp>0)
	{
		if(pos==1)
			t2=last;
		else
		{
			for(int i=pos-1;i>0;i++)
			t2=t2->next;
		}
		p=t2->next;
		t2->next= t2->next->next;
		free(p);
	}
	else 
	{
		cout<<"\nUnderFlow!!!";
	}
}
template <class t>
void clist<t>:: deleteAfterX()
{
	int pos=search();
	node<t> *t2=first;
	node<t> *p;
	int temp=count();
	if(temp>0)
	{
		if(pos==1)
			t2=last;
		else
		{
			for(int i=pos-2;i>0;i++)
			t2=t2->next;
		}
		p=t2->next;
		t2->next= t2->next->next;
		free(p);
	}
	else 
	{
		cout<<"\nUnderFlow!!!";
	}
}

int main()
{
	clist<int> l1;

	int ch=0;
	int data,x,t;
	l1.create();

	while(1)
	{
		cout<<"\n\nMenu:\n";
		cout<<"1. Insert a node\n";
		cout<<"2. Show all\n";
		cout<<"3. Delete after element 'x'\n";
		cout<<"4. Search a number\n";
		cout<<"5. Reverse DLL.\n";
		cout<<"6. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				l1.insertX();
				break;
			
			case 2:
				l1.display();
				break;

			case 3:
				l1.deleteX();
				break;

			case 4:
				l1.search();
				break;

			case 5:
				l1.reverse();
				cout<<"Circular Linked list is reversed.\n";
				l1.display();
				break;

			case 6 :
				break;

			default:
				cout<<"\n\n\t\t!!!!Wrong choice!!!!\n";
				break;
		}
		if(ch==6)
		break;
	}
}
