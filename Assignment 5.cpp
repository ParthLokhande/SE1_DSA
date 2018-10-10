//============================================================================
// Name        : Pinnac.cpp
// Author      : Parth
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

struct node
{
	string name;
	int prn;
	node* next;
};

class Pinnacle
{

	struct node *p,*temp,*start,*q, *newno,*newnod,*head,*temp1;
			int n,i=1,pr;
public:

	void Ins();
	void display();
	void add();
	void del();
	void Rev();

};

void Pinnacle :: Ins()
{


	    string na;

	cout<<"Enter Total No. of Students:";
			cin>>n;
	cout<<"Enter Name of Member "<<i<<":";
	cin>>na;
	cout<<"Enter PRN NO. of Member "<<i<<":";
	cin>>pr;
	cout<<"\n";
	temp=new node;
	temp->name=na;
	temp->prn=pr;
	p=temp;
	start=temp;
	q=temp->next;

	for(i=2;i<=n;i++)
	{
		cout<<"\nEnter Name of Member "<<i<<":";
			cin>>na;
			cout<<"\nEnter PRN NO. of Member "<<i<<":";
			cin>>pr;
			cout<<"\n";
		temp=new node;
		temp->name=na;
		temp->prn=pr;
		temp->next=NULL;
		p->next=temp;
		p=p->next;
	}




}

void Pinnacle :: display()
{
	cout<<"\nMembers are:";

	               p=start;
				   while(p->next!=NULL)
				{
				  	cout<<"\nName:"<<p->name;
				  	cout<<"\t"<<"| PRN:"<<p->prn;
				  	p=p->next;
				}
				   cout<<"\nName:"<<p->name<<" | PRN:"<<p->prn;

				   cout<<"\n\n**********Pinnacle Club Head**********";
				   cout<<"\nPresident is "<<start->name;
						   cout<<"\t"<<"| PRN:"<<start->prn;
				   cout<<"\nSecratary is "<<p->name;
						   cout<<"\t"<<"| PRN:"<<p->prn<<"\n\n";
}



	void Pinnacle ::add()
	{
	    int c;
	    int prnn;
	    string namee;
	    p=start;
	    struct node *newnode,*store;
	    cout<<"\n\n1.Add New President";
	    cout<<"\n2.Add New Member";
	    cout<<"\n3.Add New Secretary";
	    cout<<"\nEnter your choice";
	    cin>>c;
	    cout<<"\nEnter name of New Member:";
	    cin>>namee;
	    cout<<"\nEnter PRN no of New Member:";
	    cin>>prnn;
	    newnode=new node;
	    newnode->name=namee;
	    newnode->prn=prnn;

	    switch(c)
	    {
	    case 1 :newnode->next=start;
	            start=newnode;
	            break;
	    case 2 :cout<<"\nEnter insert position:prn no";
	        cin>>prnn;
	        if(p->prn!=prnn)
	        {
	            p=p->next;
	        }
	        store= new node;
	        store=p->next;
	        p->next=newnode;
	        newnode->next=store;
	        break;
	    case 3 :if(p->next!=NULL)
	            {
	                p=p->next;
	            }
	            p=p->next;
	            p->next=newnode;
	            newnode->next=NULL;
	            break;
	    default :cout<<"\n!!enter valid no!!";
	            break;
	    }

	}

	void Pinnacle ::del()
	{
	    int prnn;
	    cout<<"\nEnter the node to be deleted(i.e. prn no):";
	    cin>>prnn;
	    p=start;
	    q=start->next;
	    if(p->prn==prnn)
	    {
	        start=q;
	        delete p;
	    }
	    else
	    {
	        while(q->prn!=prnn)
	        {
	            p=p->next;
	            q=q->next;
	        }
	    }
	    if(q->next==NULL)
	    {
	        p->next=NULL;
	        delete q;
	    }
	    else
	    {
	        p->next=q->next;
	        delete q;
	    }


	}








/*void Pinnacle :: Rev()
{
	if(n!=0)
	{
		temp1=head;
		for(int)
	}
}*/

int main(void)
{
	Pinnacle obj;
	int v;
	char y;
	obj.Ins();
	obj.display();
	cout<<"\nWhat do You want to do?";
	cout<<"\n1.Add Member";
	cout<<"\n2.Delete Member";
	cout<<"\nEnter Your Choice:";
	cin>>v;
	switch(v)
	{
	case 1:
		obj.add();
		cout<<"\nDo you want to print New List?(yes or no)";
		cin>>y;
		if(y=='y'||y=='Y')
		{
			obj.display();
		}
		break;
	case 2:
		obj.del();
		cout<<"\nDo you want to print New List?(yes or no)";
				cin>>y;
				if(y=='y'||y=='Y')
				{
					obj.display();
				}
				break;
		break;
	default:
		cout<<"\nEnter a Valid NO.";
	}
}
