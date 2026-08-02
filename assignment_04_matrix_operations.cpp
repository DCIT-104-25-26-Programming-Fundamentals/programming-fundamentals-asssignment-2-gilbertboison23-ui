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

void readMatrix(int matrix[10][10], int rows, int cols, string label) {
    cout << "\nEnter " << label << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols, string title) {
    cout << "\n" << title << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int matrix[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB, int result[10][10]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int total = 0;
            for (int k = 0; k < colsA; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

int main() {
    int matrix[10][10], transposed[10][10];
    int rows, cols;

    // --- Part A: Transpose ---
    cout << "=== Part A: Transpose a Matrix ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols, "the matrix");
    printMatrix(matrix, rows, cols, "Original Matrix");

    transpose(matrix, rows, cols, transposed);
    printMatrix(transposed, cols, rows, "Transposed Matrix");

    // --- Part B: Addition ---
    cout << "\n=== Part B: Add Two Matrices ===" << endl;
    cout << "Both matrices must be " << rows << " x " << cols << "." << endl;

    int matrixA[10][10], matrixB[10][10], sumResult[10][10];
    readMatrix(matrixA, rows, cols, "Matrix A");
    readMatrix(matrixB, rows, cols, "Matrix B");

    printMatrix(matrixA, rows, cols, "Matrix A");
    printMatrix(matrixB, rows, cols, "Matrix B");

    addMatrices(matrixA, matrixB, rows, cols, sumResult);
    printMatrix(sumResult, rows, cols, "Sum (A + B)");

    // --- Part C: Multiplication ---
    cout << "\n=== Part C: Multiply Two Matrices ===" << endl;
    int m, n, p;
    cout << "Enter rows for Matrix A (M): ";
    cin >> m;
    cout << "Enter columns for Matrix A / rows for Matrix B (N): ";
    cin >> n;
    cout << "Enter columns for Matrix B (P): ";
    cin >> p;

    int matrixA2[10][10], matrixB2[10][10], product[10][10];
    readMatrix(matrixA2, m, n, "Matrix A");
    readMatrix(matrixB2, n, p, "Matrix B");

    printMatrix(matrixA2, m, n, "Matrix A");
    printMatrix(matrixB2, n, p, "Matrix B");

    multiplyMatrices(matrixA2, matrixB2, m, n, p, product);
    printMatrix(product, m, p, "Product (A x B)");

    return 0;
}