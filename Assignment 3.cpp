#include<iostream>
#include<string>
using namespace std;
class operation
{
	private: string s1,s2,s3;
	int i,j;

	public: void get()
			{
				cout<<"\n enter the string";
				cin>>s1;
				cout<<"\n enter the string";
				cin>>s2;
			}
			void put()
			{
				cout<<"\n string is:";
				cout<<s1;
				cout<<"\n string is:";
				cout<<s2;
			}
			void lnth()
			{
				int count=0;

				for(i=0;s1[i]!='\0';i++)
				{
					count++;
				}
				cout<<"\n length of string is ="<<count;
			}
			void copy()
			{

				for(i=0;s1[i]!='\0';i++)
				{

						s2[i]=s1[i];

				}
				//s2[i]='\0';
				cout<<"\n copied string is="<<s2;

			}
			void concat()
			{j=0;

				for(i=0;s1[i]!='\0';i++)
				{
					s3[j]=s1[i];
					j++;

				}
				int k=j;
				for(j=0;s2[j]!='\0';j++)
				{
					s3[k]=s2[j];
					k++;
				}
				s3[k]='\0';
				cout<<"\n concat string is="<<s3;
			}

};
int main()
{
	operation s;
	s.get();
	s.put();
	s.lnth();
	s.copy();
	s.concat();
	return 0;
}

