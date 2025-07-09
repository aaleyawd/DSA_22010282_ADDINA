/* 
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 2 (Easy Level) - Efficiently compute sums of diagonals of a matrix
Problem: https://geeksforgeeks.org/efficiently-compute-sums-of-diagonals-of-a-matrix/
*/

#include <iostream>
#include <vector> // Use vector for dynamic size safety
using namespace std;

void computeDiagonalSums(const vector<vector<int>>& matrix, int n)
{
    int principalDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < n; i++)
    {
        principalDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }

    cout << "\nOutput:\n";
    cout << "Primary Diagonal Sum: " << principalDiagonalSum << endl;
    cout << "Secondary Diagonal Sum: " << secondaryDiagonalSum << endl;
}

int main()
{
    int n;

    cout << "Input matrix size n: ";
    cin >> n;

    // Use vector for safer memory management
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix (" << n*n << " values):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    computeDiagonalSums(matrix, n);

    return 0;
}
