/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 2 (Hard Level) - A Boolean Matrix Question
Problem: https://geeksforgeeks.org/a-boolean-matrix-question/
*/

#include <iostream>
#include <vector>
using namespace std;

void updateMatrix(vector<vector<int>>& matrix, int row, int column) {
    vector<bool> rowMark(row, false);
    vector<bool> columnMark(column, false);

    // First pass: identify rows and columns to mark
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] == 1) {
                rowMark[i] = true;
                columnMark[j] = true;
            }
        }
    }

    // Second pass: update matrix based on marks
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (rowMark[i] || columnMark[j]) {
                matrix[i][j] = 1;
            }
        }
    }

    // Output result
    cout << "\nOutput:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row, column;

    cout << "Enter matrix size (row column): ";
    cin >> row >> column;

    // Use vector for dynamic and safer memory
    vector<vector<int>> matrix(row, vector<int>(column));

    cout << "Enter " << row * column << " elements (0 or 1):\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix[i][j];
        }
    }

    updateMatrix(matrix, row, column);

    return 0;
}
