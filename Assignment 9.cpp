
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class infixed
{
public:
	char infix[20];
	char  postfix[20];
	int top;
	char token,ch;

public:
	void i_postfix();
	int priority(char y);

	infixed()
	{
		top=-1;
		token=0;
		ch=0;
	}
	int isempty()
	{
		if(top==-1)
		{
			return 1;
			}
		else
		{
			return 0;
		}
	}
	int isfull()
	{
		if(top==19)
		{
			return 1;
		}
		else
		{
			return 0;
			}
	}
	void push(char x)
	{
		if(isfull())
		{
			cout<<"stack is full";
		}
		else
		{
			top++;
			postfix[top]=x;
		}
	}
	int pop()
	{
		if(isempty())
		{
			cout<<"stack is empty";
		}
		else
		{
			top--;
		}
		}
	char gettop()
	{
		if(isempty())
		{
			cout<<"empty";
		}
		else
		{
			return postfix[top];
		}
	}
	void accept()
	{
		cin>>infix;
	}
	void display()
	{
		cout<<"statement<<xyz";
	}
};
void infixed ::i_postfix()
		{
			 int k=0;
			for(int i=0;infix[i]!='\0';i++)
			{
				token=infix[i];
				if(token=='(')
								{
									push(token);
								}
								else if(token==')')
								{
									while((k=pop())!='(')
									{
										k=pop();
										postfix[ch]=k;
										k++;
										}
									if(token=='+'|| token=='-'|| token=='*'|| token=='/')
									{
										while(priority(gettop())>=priority(token))
										{
											k=pop();
											postfix[ch]=k;
											ch++;
										}
											push(token);
									}
								 else
									{
									 	 postfix[ch]=token;
									 	 k++;
									}

								}
							}

  int infixed::priority(char y)
  {

  }
if(y=='+'||y=='-')
{
	return 1;
}
else if(y=='*'||y=='/')
{
	return 2;
}
else if(y=='*'||y=='^')
{
	return 3;
}
}

int main()
{
	infixed i1;
	i1.accept();
	i1.i_postfix();
	i1.display();
	return 0;
}
