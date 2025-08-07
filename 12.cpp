#include <iostream>
#include <iomanip>
using namespace std;

// Function to generate magic square for odd n using Siamese method
void generateOddMagicSquare(int n, int square[50][50]) {
    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n) {
        square[i][j] = num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (square[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }
}

// Function to generate magic square for doubly even n
void generateDoublyEvenMagicSquare(int n, int square[50][50]) {
    int num = 1;
    int total = n * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = num++;
        }
    }

    // Replace specific pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((i / 4 + j / 4) % 2) == 0)
                square[i][j] = total - (i * n + j);
        }
    }
}

// Function to print the square
void printSquare(int square[50][50], int n) {
    cout << "\nMagic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << square[i][j];
        }
        cout << endl;
    }
}

// Function to verify the magic square
void verifyMagicSquare(int square[50][50], int n) {
    int magicSum = n * (n * n + 1) / 2;
    bool isValid = true;

    // Check rows and columns
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) {
            isValid = false;
            break;
        }
    }

    // Check diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += square[i][i];
        diag2 += square[i][n - i - 1];
    }

    if (diag1 != magicSum || diag2 != magicSum) {
        isValid = false;
    }

    cout << "\nVerification: ";
    if (isValid)
        cout << "This is a valid magic square. Magic constant = " << magicSum << endl;
    else
        cout << "This is NOT a valid magic square." << endl;
}

int main() {
    int n, square[50][50] = {0};

    cout << "Enter the order of the magic square (n): ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for order less than 3.\n";
        return 1;
    }

    if (n % 2 == 1) {
        generateOddMagicSquare(n, square);
    } else if (n % 4 == 0) {
        generateDoublyEvenMagicSquare(n, square);
    } else {
        cout << "Magic square for singly even order (e.g., 6, 10) is not implemented.\n";
        return 1;
    }

    printSquare(square, n);
    verifyMagicSquare(square, n);

    return 0;
}
