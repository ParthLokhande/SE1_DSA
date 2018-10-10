//============================================================================
// Name        : Assi2.cpp
// Author      : Parth
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;

class student
{
	int i,roll[30];
	string name[30];
	int m;
public:

	void getsdata();
	void displaydata();
	void uni(student ,student);
	void inter(student,student);
	void differ(student, student);
	int getm()
	{return m;}
};

void student :: getsdata()
{
	cout<<"Enter Total No. of students:";
	cin>>m;
		for(i=0;i<m;i++)
			{
			   cout<<"\nEnter Name of Student:";
			   cin>>name[i];
			   cout<<"Enter Roll No. of Student:";
			   cin>>roll[i];
			}
}

void student :: displaydata()
{
	cout<<"{";
	for(i=0;i<m;i++)
	{
		cout<<name[i]<<"-"<<roll[i];
		if(i!=m-1)
			cout<<",";
	}
	cout<<"}"<<"\n";
}

	void student :: uni(student a, student b)
		{
			int count=0,flag;
				for(int k=0;k<a.m;k++)
				{
					roll[k]=a.roll[k];
					name[k]=a.name[k];
					count++;
				}
				for(int i=0;i<b.m;i++)
				{
					flag=0;
						for(int j=0;j<a.m;j++)
						{
							if(b.roll[i]==a.roll[j])
							{
								flag=1;
								break;
							}
						}

							if(flag==0)
						{
							roll[count]=b.roll[i];
							name[count]=b.name[i];
							count++;
						}

				}
		 m=count;
		 cout<<"\nNumber of students playing both Cricket and Badminton(Union):"<<m<<"\n";
		}

	void student :: inter(student a, student b)
			{
				int count=0,flag;
					for(int k=0;k<a.m;k++)
					{
						roll[k]=a.roll[k];
						name[k]=a.name[k];
						count++;
					}
					for(int i=0;i<b.m;i++)
					{
						flag=0;
							for(int j=0;j<a.m;j++)
							{
								if(b.roll[i]==a.roll[j])
								{
									flag=1;
									break;
								}
							}

								if(flag==1)
							{
								roll[count]=a.roll[i];
								name[count]=a.name[i];
								count--;
							}

					}
			 m=count;
			 cout<<"\nNumber of students playing both Cricket and Badminton(Intersection):"<<m<<"\n";
			}

	void student :: differ(student a,student b)
	{
	    int k=0;
	    for(int i=0;i<b.m;i++)
		{
			int f=0;
			for(int j=0;j<a.m;j++)
			{
				if(b.roll[i]== a.roll[j])
				{
					f++;
					break;
				}
			}
			if(f==0)
			{
				roll[k]=b.roll[i];
				name[k]=b.name[i];
				k++;
			}
		}
		m=k;
	}




int main()
{
	int n;
	student cr,bm,un,in,di;
	int x;
	cout<<"Enter details of student Playing cricket\n";
	cr.getsdata();
	cout<<"\nEnter details of student Playing Badminton\n";
	bm.getsdata();
	cout<<"1:Find out Union\n";
	cout<<"2:Find out Intersection\n:";
	cout<<"3:Find out Difference (Cricket-Badminton\n";
	cout<<"4:Find out Difference (Badminton-Cricket)\n";
	cout<<"5:Neither Cricket Nor Badminton\n";
	cout<<"Enter Your Choice:";
	cin>>x;

	switch(x)
	{
	case 1:
		{
			un.uni(cr,bm);
				cout<<"\nStudents playing both Cricket and Badminton:";
				un.displaydata();
				break;
		}
	case 2:
		{
			in.inter(cr,bm);
				cout<<"\nStudents playing both Cricket and Badminton:";
				in.displaydata();
				break;
		}
	case 3:
		{
			cout<<"\nStudents playing Badminton:";
				di.differ(cr,bm);
				di.displaydata();
				break;
		}
	case 4:
		{
			cout<<"\nStudents playing Cricket:";
				di.differ(bm,cr);
				di.displaydata();
				break;
		}
	case 5:
		{
			un.uni(cr,bm);
			cout<<"\nNumber of Students playing neither Cricket nor Badminton are:"<<(30-un.getm());
			break;
		}
	default:
		{
		cout<<"Please Enter a Valid Number";
		break;
		}
	}
	return 0;
}
