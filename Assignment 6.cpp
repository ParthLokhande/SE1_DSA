//============================================================================
// Name        : PVR.cpp
// Author      : Parth
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node{
	char status;
	string name;
	struct node *next, *prev;
};
class pvr{
	int row,col;
	struct node *temp, *p, *start ,*q, *start1[10];
public:
	void create();
	void display();
	void book();
	void cancel();
};

void pvr :: create()
{
	temp=new node;
	temp->status='A';
	temp->next=NULL;
	temp->prev=NULL;
	p=temp;
	start=temp;
	for(int i=0;i<7;i++)
	{
		temp=new node;
		temp->status='A';
		temp->next=NULL;
		temp->prev=p;
		p->next=temp;
		p=p->next;
	}


}
void pvr :: display()
{
	p=start;

	while(p->next!=NULL)
	{
		cout<<p->status<<"\t";
		p=p->next;
	}
}

void pvr :: book()
{
	char t;
	string nam;

	Rep:cout<<"\nEnter Seat Number you want to book:";
	cin>>col;
	cout<<"\nAre you sure you want to Book this seat?";
	cin>>t;
	if(t=='y'||t=='Y')
	{
		p=start;

		for(int j=1;j<col;j++)
		{
			p=p->next;
		}
		p->status='B';
		cout<<"\nEnter your name:";
		cin>>nam;
		cout<<"\n*****You have Successfully Booked the Ticket*****";



	}
	else
	{
		cout<<"\nPlease Try again!";
		goto Rep;
	}

}

void pvr :: cancel()
{

}

int main(void)
{
	int i;
  pvr ticket[10];
  for(int i=0;i<10;i++)
  {
	  ticket[i].create();

  }


  for(int j=1;j<8;j++)
  	{
  		cout<<"\t";
  		cout<<j;
  	}
  cout<<"\n";
  for(int i=0;i<10;i++)
  {
	  cout<<(i+1)<<"\t";
	  ticket[i].display();
	  cout<<"\n";
  }
  cout<<"===========================================================";
  cout<<"\n\t\t\tScreen";
  cout<<"\n===========================================================";

  int o;
  cout<<"\nMenu";
  cout<<"\n1.Book Ticket";
  cout<<"\n2.Cancel Ticket";
  cout<<"\n3.Exit";
  cout<<"\nEnter Your Choice:";
  cin>>o;

  switch(o)
  {
  case 1:

	  cout<<"\nEnter Row No.";
	  cin>>i;
	  ticket[i].book();
	  cout<<"\n\n";
	  for(int j=1;j<8;j++)
	    	{
	    		cout<<"\t";
	    		cout<<j;
	    	}
	  cout<<"\n";
	  for(int i=0;i<10;i++)
	    {
	  	  cout<<(i+1)<<"\t";
	  	  ticket[i].display();
	  	  cout<<"\n";
	    }



  }


}
