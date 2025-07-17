// 170725_1415 taking matrix input from users and displaying it
#include <iostream>
using namespace std;
int main() 
{
    int rows, cols;
    cout << "enter no. of rows: \n";
    cin >> rows;
    cout << "enter no. of columns: \n";
    cin >> cols;
    int matrix[50][50];
    cout << "enter elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << "element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nmatrix:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}