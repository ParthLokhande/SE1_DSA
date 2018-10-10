//============================================================================
// Name        : sparse1a.cpp
// Author      : Parth
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class Matrix
{
    int r,c;
    int mat[5][5];
    int sparse[10][3];
    int transpose[10][3];
public:
    void accept();
    void accept_s();
    void display();
    int fsparse();
    void ftranspose(int);
    void fstranspose(int);
     void fadd(Matrix, Matrix);

};

void Matrix::accept()
{
    int i,j;
    cout<<"\nEnter No of rows:";
    cin>>r;
    cout<<"Enter No of columns:";
    cin>>c;
    cout<<"\nEnter elements:"<<endl;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<"Matrix["<<i<<"]["<<j<<"] = ";
            cin>>mat[i][j];
        }

    }

}


void Matrix::display()
{
    int i,j;
    cout<<"The matrix you entered is:"<<endl;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }

}

int Matrix::fsparse()
{
    int i,j,k,cnt;
    k=1;cnt=0;


    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=mat[i][j];
                k++;
                cnt++;
            }
        }
    }

    sparse[0][0]=r;
    sparse[0][1]=c;
    sparse[0][2]=cnt;


	cout<<"\nThe 3 col Representation of your matrix:"<<endl;
    for(i=0;i<(cnt+1);i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<sparse[i][j]<<"\t";
        }
        cout<<"\n";
    }

    return cnt;


}

void Matrix::fstranspose(int cnt)
{
	int row,col,nz;
	row=sparse[0][0];
	col=sparse[0][1];
	nz=sparse[0][2];

	transpose[0][0]=sparse[0][1];
	transpose[0][1]=sparse[0][0];
	transpose[0][2]=sparse[0][2];

	int i,j,k;
	k=1;
	for(i=0;i<col;i++)
	{
		for(j=0;j<=nz;j++)
		{
			if(i==sparse[j][1])
			{
				transpose[k][0]=sparse[j][1];
				transpose[k][1]=sparse[j][0];
				transpose[k][2]=sparse[j][2];
				k++;
			}
		}
	}

	 for(i=0;i<(cnt+1);i++)
    	{
        	for(j=0;j<3;j++)
	        {
	            cout<<transpose[i][j]<<"\t";
	        }
	        cout<<"\n";
	    }

}

void Matrix::ftranspose(int cnt)
{
    int row, col, nz;
    int i,index;

    row=sparse[0][0];
    col=sparse[0][1];
    nz=sparse[0][2];

    transpose[0][0]=col;
    transpose[0][1]=row;
    transpose[0][2]=nz;

    int terms[col],rpos[col];

    for(i=0;i<col;i++)
    {terms[i]=0;}


    for(i=1;i<=nz;i++)
    {
        index=sparse[i][1];
        terms[index]++;
    }


    rpos[0]=1;
    for(i=1;i<col;i++)
    {
        rpos[i]=rpos[i-1]+terms[i-1];
    }


    int k;
    for(i=1;i<=nz;i++)
    {
        k=rpos[sparse[i][1]];
        transpose[k][0]=sparse[i][1];
        transpose[k][1]=sparse[i][0];
        transpose[k][2]=sparse[i][2];
        rpos[sparse[i][1]]++;

    }


    for(i=0;i<(cnt+1);i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<transpose[i][j]<<"\t";
        }
        cout<<"\n";
    }
}


void Matrix::fadd(Matrix A, Matrix B)
{
	int i,j,k;
	i=1;j=1;k=1;

	if((A.sparse[0][0]==B.sparse[0][0]) && (A.sparse[0][1]==B.sparse[0][1]))
	{
	    sparse[0][0]=A.sparse[0][0];
		sparse[0][1]=A.sparse[0][1];

		while((i<=A.sparse[0][2])&&(j<=B.sparse[0][2]))
		{
			if(A.sparse[i][0]==B.sparse[j][0])
			{
				if(A.sparse[i][1]==B.sparse[j][1])
				{
					sparse[k][0]=A.sparse[i][0];
					sparse[k][1]=A.sparse[i][1];
					sparse[k][2]=A.sparse[i][2]+B.sparse[j][2];
					i++;j++;k++;
				}
				else if(A.sparse[i][1]>B.sparse[j][1])
				{
					sparse[k][0]=B.sparse[j][0];
					sparse[k][1]=B.sparse[j][1];
					sparse[k][2]=B.sparse[j][2];
					j++;k++;
				}
				else
				{
					sparse[k][0]=A.sparse[i][0];
					sparse[k][1]=A.sparse[i][1];
					sparse[k][2]=A.sparse[i][2];
					i++;k++;
				}
			}

            else if(A.sparse[i][0]>B.sparse[j][0])
            {
                sparse[k][0]=B.sparse[j][0];
                sparse[k][1]=B.sparse[j][1];
                sparse[k][2]=B.sparse[j][2];
                j++;k++;
            }

            else
            {
                sparse[k][0]=A.sparse[i][0];
                sparse[k][1]=A.sparse[i][1];
                sparse[k][2]=A.sparse[i][2];
                i++;k++;
            }

		}

		while(i<=A.sparse[0][2])
		{
			sparse[k][0]=A.sparse[i][0];
			sparse[k][1]=A.sparse[i][1];
			sparse[k][2]=A.sparse[i][2];
			i++;k++;
		}

		while(j<=B.sparse[0][2])
		{
			sparse[k][0]=B.sparse[j][0];
			sparse[k][1]=B.sparse[j][1];
			sparse[k][2]=B.sparse[j][2];
			j++;k++;
		}


		sparse[0][2]=k-1;
	}


	    for(i=0;i<=sparse[0][2];i++)
	    {
		for(j=0;j<3;j++)
		{
		    cout<<sparse[i][j]<<"\t";
		}
		cout<<"\n";
	    }


}

int main()
{

Matrix M,M1,M2,M3;
int choice,elements;
char ch;
bool done=false;




do
{
	cout<<"\nWhat operation do you want to perform?";
    cout<<"\n1. Enter Matrix.";
    cout<<"\n2. Display matrix in 3 col representation.";
    cout<<"\n3. Display simple transpose.";
    cout<<"\n4. Display fast transpose.";
    cout<<"\n5. Addition of 2 matrices.";
    cout<<"\n6. Exit";

    cout<<"\nEnter your Choice:"
    cin>>choice;

    switch(choice)
    {
        case 1 :    M.accept();
                    break;
        case 2 :    elements=M.fsparse();
                    break;
        case 3 :    M.fstranspose(elements);
                    break;
        case 4 :    M.ftranspose(elements);
                    break;
        case 5 :    cout<<"Enter first matrix : ";
                    M1.accept();
                    M1.fsparse();
                    cout<<"\nEnter second matrix : ";
                    M2.accept();
                    M2.fsparse();
                    cout<<"Their addition in sparse representation is : "<<endl;
                    M3.fadd(M1,M2);
                    break;
        case 6:    done=true;
                    break;
    }



}while(done==false);



}
