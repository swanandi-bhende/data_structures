// displaying the sparse matrix in triple form
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
    int integers=0;
    cout<<"enter elements of the matrix:\n";
    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            cout<<"element at [" << i << "][" << j << "]: ";
            cin>>matrix[i][j];
            if (matrix[i][j]!=0) 
                integers++;
        }
    }
    cout<<"\nMatrix:\n";
    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            cout<<matrix[i][j]<< " ";
        }
        cout<<endl;
    }
    if (integers>total/2) 
    {
        cout << "normal matrix\n";
        return 0;
    }
    cout<<"sparse matrix in triplet form:\n";
    cout<<"row  col  value\n";
    cout<<rows<< "    " << cols << "    " << integers << "\n";
    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            if (matrix[i][j]!=0) 
            {
                cout<<i<< "    " << j << "    " << matrix[i][j] << "\n";
            }
        }
    }
    return 0;
}