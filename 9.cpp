// 1536_1537 using fast transpose algorithm
#include <iostream>
using namespace std;
#define MAX_TERMS 100
struct TERM 
{
    int row;
    int col;
    int value;
};
void fast_transpose(TERM a[], TERM b[]) 
{
    int row_terms[25] = {0};      
    int starting_pos[25] = {0};
    int num_cols = a[0].col;
    int num_terms = a[0].value;
    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;
    if (num_terms > 0) 
    {
        for (int i = 1; i <= num_terms; i++) 
        {
            row_terms[a[i].col]++;
        }
        starting_pos[0] = 1;
        for (int i = 1; i < num_cols; i++) 
        {
            starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
        }
        for (int i = 1; i <= num_terms; i++) 
        {
            int col = a[i].col;
            int pos = starting_pos[col];
            b[pos].row = a[i].col;
            b[pos].col = a[i].row;
            b[pos].value = a[i].value;
            starting_pos[col]++;
        }
    }
}
int main() 
{
    int rows, cols;
    cout << "enter number of rows: \n";
    cin >> rows;
    cout << "enter number of columns: \n";
    cin >> cols;
    int matrix[25][25];
    int total = rows * cols;
    int nonZeroCount = 0;
    cout << "enter elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << "element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
            if (matrix[i][j] != 0)
                nonZeroCount++;
        }
    }
    cout << "matrix:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    if (nonZeroCount > total / 2) 
    {
        cout << "normal matrix.\n";
        return 0;
    }
    TERM A[MAX_TERMS], B[MAX_TERMS];
    int idx = 1;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (matrix[i][j] != 0) 
            {
                A[idx].row = i;
                A[idx].col = j;
                A[idx].value = matrix[i][j];
                idx++;
            }
        }
    }
    A[0].row = rows;
    A[0].col = cols;
    A[0].value = nonZeroCount;
    cout << "sparse matrix in triplet form:\n";
    cout << "row  col  value\n";
    for (int i = 0; i < idx; ++i) 
    {
        cout << A[i].row << "    " << A[i].col << "    " << A[i].value << "\n";
    }
    fast_transpose(A, B);
    cout << "transpose of sparse matrix:\n";
    cout << "row  col  value\n";
    for (int i = 0; i <= nonZeroCount; ++i) 
    {
        cout << B[i].row << "    " << B[i].col << "    " << B[i].value << "\n";
    }
    return 0;
}