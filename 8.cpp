// 170725_1520 showing transpose of the sparse matrix 
#include <iostream>
using namespace std;
int main() 
{
    int rows, cols;
    cout<<"enter number of rows: \n";
    cin>>rows;
    cout<<"enter number of columns: \n";
    cin>>cols;
    int matrix[25][25];
    int total=rows*cols;
    int nonZeroCount = 0;
    cout<<"enter elements of the matrix:\n";
    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            cout<<"element at ["<<i<<"]["<<j<<"]: ";
            cin>>matrix[i][j];
            if (matrix[i][j]!=0)
                nonZeroCount++;
        }
    }
    cout<<"Matrix:\n";
    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    if (nonZeroCount>total/2) 
    {
        cout<<"normal matrix.\n";
        return 0;
    }
    int A[100][3]; 
    int idx=1; 

    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            if (matrix[i][j]!=0) 
            {
                A[idx][0]=i;
                A[idx][1]=j;
                A[idx][2]=matrix[i][j];
                idx++;
            }
        }
    }
    A[0][0]=rows;
    A[0][1]=cols;
    A[0][2]=nonZeroCount;
    cout << "sparse matrix in triplet form:\n";
    cout << "row  col  value\n";
    for (int i=0; i<idx; ++i) 
    {
        cout<<A[i][0]<<"    "<<A[i][1]<<"    "<<A[i][2]<<"\n";
    }
    int B[100][3];
    B[0][0]=A[0][1]; 
    B[0][1]=A[0][0]; 
    B[0][2]=A[0][2];
    int noterms=A[0][2];
    int noc=A[0][1];
    int nxt=1;
    if (noterms>0) 
    {
        for (int c=0; c<noc; ++c) 
        {
            for (int term=1; term<=noterms; ++term) 
            {
                if (A[term][1]==c) 
                {
                    B[nxt][0]=A[term][1];
                    B[nxt][1]=A[term][0]; 
                    B[nxt][2]=A[term][2];
                    nxt++;
                }
            }
        }
    }
    cout << "transpose of sparse matrix:\n";
    cout << "row  col  value\n";
    for (int i=0; i<nxt; ++i) 
    {
        cout<<B[i][0]<<"    "<<B[i][1]<<"    "<<B[i][2]<<"\n";
    }
    return 0;
}