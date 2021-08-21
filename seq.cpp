#include <bits/stdc++.h>
#include <time.h>
#include <chrono>

using namespace std::chrono;
using namespace std;
 
//size of the matrix
#define N 100

// function to multiply two matrices and the then it stores the result of the multiplication in a result matrix 
void multiply(int matrix1[][N], int matrix2[][N], int result[][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

//function to fill the matrix with random values
void initialize(int matrix[N][N], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

//function to print a matrix to the console
void print_matrix(int matrix[N][N])
{
    cout << "Matrix: \n";
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << ", "S;
		cout << "\n";
	}
}
 
//main function
int main()
{
	//initialize the matrices (matrix 1, 2, and result) 
	int result[N][N], matrix1[N][N], matrix2[N][N]; 
	initialize(matrix1, N, N);
	initialize(matrix2, N, N);
	
	//start time variable
	auto start = high_resolution_clock::now();
	
	//multiply the 2 matrices
   	multiply(matrix1, matrix2, result);
    	
	//stop time variable
	auto stop = high_resolution_clock::now();

	//calculate the time taken by the function
	auto duration = duration_cast<microseconds>(stop - start);
	
	//print the result function
	print_matrix(result)
	
	// print the time taken
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

	return 0;
}
