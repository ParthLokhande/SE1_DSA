//============================================================================
// Name        : assignment_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next,*prev;
};

class binary{
	int n;
	struct node *temp,*start,*p,*q;
public:
	void accept();
	void display();
	void ones();
	void twos();
	void addi();
};

void binary :: accept(){
	short int a;
	cout << "\nEnter No. of Bits:";
	cin >> n;
	cout << "\nEnter Bit No.1:";
	cin >> a;
	temp = new node;
	temp->data = a;
	temp->next = NULL;
	temp->prev = NULL;
	p = temp;
	start = temp;
	for(int i = 2; i <= n ; i++){
		cout << "\nEnter Bit No." << i <<":";
		cin >> a;
		temp = new node;
		temp->data = a;
		temp->next = NULL;
		temp->prev = p;
		p->next = temp;
		p = p->next;
	}
}

void binary :: display(){
	p = start;
	cout << "\nBinary  Number:";
while(p->next!=NULL){
		cout << p->data;
		p=p->next;
	}
	cout << p->data;
}

void binary :: ones(){
	q=start;
	cout << "\n\nOnes Complement is:";
	while(q->next!=NULL){
		if(q->data == 1){
			q->data=0;
			q=q->next;
		}
		else{
			q->data=1;
			q=q->next;
		}
	}
	if(q->data == 1)
				q->data=0;
			else
				q->data=1;

	q=start;
	while(q->next!=NULL){
			cout << q->data;
			q=q->next;
		}
		cout << q->data;

}

void binary :: twos(){
	cout<<"\n\nTwos Complement:";
	q=start;

	while(q->next!=NULL){
		q=q->next;
	}
	if(q->data == 0){
		q->data = q->data+1;
		q=start;
			while(q->next!=NULL){
					cout << q->data;
					q=q->next;
				}
				cout << q->data;
	}
	else{
                q->data=0;
                while(q->prev!=NULL){
                	q=q->prev;
                	if(q->data == 0){
                		q->data=q->data+1;
                		q=q->prev;
                		break;
                	}
                	else{
                		q->data = 0;
                		q=q->prev;
                	}
                }
               /* if(q->data == 0)
                      q->data=q->data+1;
                else
                      q->data = 0;*/

                q=start;
                		while(q->next!=NULL){
                				cout << q->data;
                				q=q->next;
                			}
                			cout << q->data;
              }



}

int main(){
	binary b;
	b.accept();
	b.display();
	b.ones();
	b.twos();
	return 0;
}
