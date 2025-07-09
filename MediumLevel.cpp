/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 2 (Medium Level) - Rotate a Matrix by 180 degrees
Problem: https://geeksforgeeks.org/rotate-matrix-180-degree/
*/

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix180(const vector<vector<int>>& matrix, int n) {
    cout << "\nOutput (Matrix rotated by 180 degrees):\n";
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter matrix size n: ";
    cin >> n;

    // Use vector for dynamic memory allocation
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter " << n * n << " elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotateMatrix180(matrix, n);

    return 0;
}
