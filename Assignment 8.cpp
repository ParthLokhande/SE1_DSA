#include <iostream>
using namespace std;

class stack{
	char a[20],b[20];
	int top,cnt;
public:
	void accept(){
		cout<<"\nHow many Characters are you going to Enter?";
		cin >>  cnt;
		cout<<"\nEnter Expression:";
		for(int i=0;i<cnt;i++){
			cin>>a[i];
		}
	}

	void display(){
		cout<<"\nEnter Expression:";
		for(int i=0;i<cnt;i++){
					cout<<a[i];
				}
	}

	int isempty(){
		if(top == -1)
			return 1;
		else return 0;
	}
	void push(){

			if(isempty()==1){
				for(int i=0;i<20;i++){
			    if(b[i]== '(' || b[i]== '[' || b[i]== '{' )
			     a[i]=b[i];
                }
			}
}
void pop(){
		for(int i=0;i<cnt;i++){
			 if(b[i]== ')' || b[i]== ']' || b[i]== '}' )


		}
	}
};

int main(){

	stack s;
	s.accept();
	s.display();
	return 0;
}
