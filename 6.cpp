// 170725_1430 check whether user inputted matrix is sparse or not
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
    cout<<"eter elements of the matrix:\n";
    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            cout<<"element at [" << i << "][" << j << "]: ";
            cin>>matrix[i][j];
            if (matrix[i][j]!=0) 
            {
                integers++;
            }
        }
    }
    cout<<"matrix:\n";
    for (int i=0; i<rows; ++i) 
    {
        for (int j=0; j<cols; ++j) 
        {
            cout<<matrix[i][j] << " ";
        }
        cout<<endl;
    }
    if (integers>total/2)
        cout<<"normal matrix.\n";
    else
        cout<<"sparse matrix.\n";

    return 0;
}