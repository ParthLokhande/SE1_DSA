//============================================================================
// Name        : fib_search.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Fib{
	int f,a,b,n;
	int fib[50],fib1[50];
public:
	void accept();
	void fibSeries();
	void fibSearch();
};

void Fib :: accept(){

	cout << "\nHow many Numbers do you want to Enter?";
	cin >> n;
	cout << "\nNow enter the Numbers one by one:\n";
	for(int i=1;i<=n;i++)
		cin >> fib1[i];
}

void Fib :: fibSeries(){
	    fib[1] = 0;
	    fib[2] = 1;
	    for (int i = 3; i <=n; i++)
	    {
	        fib[i] = fib[i-1] + fib[i-2];
	     }

	    cout << "\nFib Series is:";
	    for(int i=1;i<=n;i++)
	    	cout << fib[i] << " ";

	    b = fib[n-1];
	    a = fib[n-2];
}

void Fib :: fibSearch(){
	int key,temp,pass=0;
	cout << "\nWhich Number Do You want to Search?";
	cin >> key;
	f=n;

	for(int i=1;i<=n;i++){
		if(key < fib1[f]){
			f = f-a;
			temp = b-a;
			b = a;
			a = temp;
			pass++;
		}

		else if(key > fib1[f]){
					f = f+a;
					b = b-a;
					a = a-b;
					pass++;
				}

		else if(key == fib1[f]){
			cout << "\n!!!Element Found!!!";
			cout<<"\nAfter " << pass << " passes";
			break;
		}
		else{
			cout << "Element Not Found!!";
			break;
		}
	}

}

int main (){
	Fib f;
	f.accept();
	f.fibSeries();
	f.fibSearch();
	return 0;
}
