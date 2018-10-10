#include<iostream>
using namespace std;


class Sort{
	float perc[];
	int n;
	public:
void bubble()
{

    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(perc[i]>perc[j])
            {
                temp=perc[i];
                perc[i]=perc[j];
                perc[j]=temp;
            }
        }
    }
}
void Accept(){
	cout << "\nHow many Percentage do you want to Enter?";
		cin >> n;
		cout <<"\nNow Enter the Percentages:";
		for(int i=0;i<n;i++){
			cin >> perc[i];
		}
}
void Display(){
	cout << "\nSorted Elements are:";
		for(int i=0;i<n;i++){
			cout << " " << perc[i];
		}
}
};


int main(){
	Sort obj;
	obj.Accept();
	obj.bubble();
	obj.Display();
	return 0;
}
