//============================================================================
// Name        : Assignment.cpp
// Author      : Parth
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>

using namespace std;

class student
{
    int rollno;
    string name;
    int marks;
public:
    static int count, max, min, absent, freq[31];
    static string abs[];
    static float sum;
    void accept();
    void display();
};

		int student :: count=0;
		int student :: max=0;
		int student :: min=30;
		int student :: absent=0;
		int student :: freq[31];
		string student :: abs[80];
		float student :: sum=0;



		void student :: accept()
	{
			cout<<"\nEnter Roll no.: ";
			cin>>rollno;
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter your marks: ";
			cin>>marks;
    if (marks >= 0)
    	{
        	count=count+1;
    	}
    else
    	{
        	absent=absent+1;
    	}



    if (marks == -1)
    	{
    		abs[absent]=student :: name;
    	}



    if (marks >= 0 & marks <= 30)
    	{
    		if (marks>max)
            	{
    				max=marks;
            	}
    		if (marks<min)
            	{
    				min=marks;
            	}
        freq[marks]++;
    }

    /*if(marks>=0)
    {
        if (marks<min)
            {
                min=marks;
            }
    }*/
    sum = sum + marks;
}

		void student :: display()
			{
				cout<<"Roll no: "<<rollno<<"\t";
				cout<<"Name: "<<name<<"\t";
				cout<<"Marks: "<<marks<<"\n";
			}

		void display1()
		{
			cout<<"\nStudents attended the test: "<<student::count;
			cout<<"\nStudents absent for the test: "<<student::absent;
			cout<<"\nAverage marks scored: "<<student :: sum / student :: count;
			cout<<"\nMaximum marks scored: "<<student::max;
			cout<<"\nMinimum marks scored: "<<student::min;
		}



void freqcount()
{
    int max,i,ref;
    max=student::freq[0];
    for(i=1;i<=30;i++)
    {
        if (student::freq[i]>max)
        {
            max=student::freq[i];
            ref=i;
        }
    }
    cout<<"\nThe frequency of marks "<<ref<<" is maximum, i.e. "<<max<<".";
}

	void absents()
		{
			int i;
			cout<<"\nList of absent students";
			for(i=1;i<=student::absent;i++)
			{
        cout<<"\n"<<i<<" "<<student :: abs[i];
			}
		}


int main()
{
    int i,m;
    cout<<"Enter total no. of students in class: ";
    cin>>m;
    student s[m];

    for(i=0;i<m;i++)
    {
        s[i].accept();
    }

    for(i=0;i<m;i++)
    {
        s[i].display();
    }
    display1();
    freqcount();
    absents();

}

