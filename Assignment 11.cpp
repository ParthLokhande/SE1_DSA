//============================================================================
// Name        : pizza.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#define size 5
using namespace std;

class Pizza{
	struct Order
	{
		int o[size];
		int front=-1,rear=-1;
	}Q;
public:
		int QFull();
		int QEmpty();
		int Accept(int);
		int Ready(int);
		int Display();
};

int Pizza :: QFull(){                                      //To check whether the Queue is Full
	if(Q.front == (Q.rear +1)%size)
		return 1;
	else
		return 0;
}

int Pizza :: QEmpty(){                                 //to check whether the Queue is Empty
	if(Q.front == -1)
		return 1;
	else
		return 0;
}

int Pizza :: Accept(int ord){                       //To Accept a Order
	if(QEmpty()){                                  //For when Queue is Empty
		Q.front = Q.rear =0;
	 	 Q.o[Q.rear] = ord;
	}
	else{                                         //After only one order is ready
		Q.rear = (Q.rear +1)%size;
        Q.o[Q.rear] = ord;
	}


	return 0;
}

int Pizza :: Ready(int p){                //Function if order is Ready
	int a;
	a=Q.o[Q.front];
	Q.o[Q.front]=0;
	Q.front = (Q.front +1)%size;           //Formula for Circular array
	cout << "\nOrder " << a << " is Ready!!\n";
	return a;

}

int Pizza :: Display(){             //Display the Queue
	int i;
	cout <<"***************\n";
	cout << "Order Queue:\n";
	int j=1;
	i= Q.front;
	while(i!=Q.rear){

		cout << j<<". " << Q.o[i] <<"\n";
		i = (i+1) % size;
		j++;
	}
	cout << j<<". " << Q.o[i] <<"\n";

	cout <<"***************\n";
	return 0;
}

int main(){
	int a,n,s,b;
	Pizza order;

	do{
		cout << "\n1.Add Order";
		cout << "\n2.Ready order";
		cout << "\n3.Display Order Queue";
		cout << "\n4.Exit";
		cout << "\nEnter your Choice:";
		cin >> s;
		cout << "\n\n";
	switch(s){
	case 1:
			if(order.QFull()){

				cout <<"\n*******Error******\n"<< "\nThe Queue is Full at the Moment!!! Please Try again Later!";
			}
			else{
			if(order.QEmpty()){   //For accepting Order in the beginning
					cout<<"How Many orders Do you want to add?";
					cin >> n;
			for(int i=1;i<=n;i++){
				cout << "\nEnter "<< i << " Order Number:";
				cin >>a;
				order.Accept(a);
    	}
    }

			else{
						cout << "\nEnter order Number:";
						cin >> a;
						order.Accept(a);
				}
			}
			break;
	case 2:
		if(order.QFull()){
        		cout <<"Enter Order Number which is Ready:";
        		cin >> b;
        		order.Ready(b);
        	}

        break;

	case 3:
		order.Display();
		break;
	case 4:
		break;
}
	}while(s!=4);
    return 0;
}
