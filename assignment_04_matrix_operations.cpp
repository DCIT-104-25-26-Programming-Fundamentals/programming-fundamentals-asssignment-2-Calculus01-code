// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int transposed[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int cols, int sum[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB, int product[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];


    int rowsA, colsA;
    int rowsB, colsB;

    cout <<"===============================" << endl;
    cout << "     MATRIX OPERATIONS PROGRAM" << endl;
    cout <<"===============================" << endl;

    cout << "\nPART A — Transpose a Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }
cout << "\n---Enter element for matrix A---" <<endl;
readMatrix (A,rowsA, colsA );

cout << "\nOriginal Matrix A:" << endl;
printMatrix(A, rowsA, colsA);

transposeMatrix(A, rowsA, colsA, C);
cout << "\nTransposed Matrix A:" << endl;
printMatrix(C, colsA, rowsA);

cout << "\nPART B — Add Two Matrices" << endl;
cout << "We will use the same dimensions ("<< rowsA << " x " << colsA << ") for both matrices." << endl;
 readMatrix(B, rowsA, colsA);

 addMatrices(A, B, rowsA, colsA, C);

 cout << "\nResult of A + B:" << endl;
 printMatrix(C, rowsA, colsA);

 cout << "\nPART C — Multiply Two Matrices" << endl;
 cout << "For multiplication (A*B), Matrix B needs new dimensions." << endl;
 cout << "Matrix A has " << colsA << " columns, so Matrix B must have " << colsA << " rows." << endl;
 rowsB = colsA;

 cout << "Enter number of columns for Matrix B: ";
 cin >> colsB;

 if (colsB <= 0 || colsB > MAX_SIZE) {
        cout << "Error: Number of columns must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }

    readMatrix(B, rowsB, colsB );

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    cout << "\nResult of Multiplication (A * B):" << endl;
    printMatrix(C, rowsA, colsB);

    return 0;
    }   