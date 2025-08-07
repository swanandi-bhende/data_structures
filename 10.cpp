// 240725_1437 sparse matrix addition
#include <iostream>
using namespace std;
struct Element 
{
    int row, col, value;
};
int main() 
{
    Element A[] = 
    {
        {0, 0, 3},
        {0, 2, 5},
        {1, 1, 7}
    };
    int sizeA = 3;
    Element B[] = 
    {
        {0, 1, 2},
        {0, 2, 4},
        {1, 1, -7}
    };
    int sizeB = 3;
    Element C[10];
    int sizeC = 0;
    int i = 0, j = 0;
    while (i < sizeA && j < sizeB) 
    {
        if (A[i].row == B[j].row && A[i].col == B[j].col) 
           {
            int sum = A[i].value + B[j].value;
            if (sum != 0) {
                C[sizeC++] = {A[i].row, A[i].col, sum};
            }
            i++; j++;
        } else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) 
        {
            C[sizeC++] = A[i++];
        } else {
            C[sizeC++] = B[j++];
        }
    }
    while (i < sizeA) C[sizeC++] = A[i++];
    while (j < sizeB) C[sizeC++] = B[j++];
    cout << "Resultant Sparse Matrix (row col value):\n";
    for (int k = 0; k < sizeC; k++) 
    {
        cout << C[k].row << " " << C[k].col << " " << C[k].value << endl;
    }
    return 0;
}