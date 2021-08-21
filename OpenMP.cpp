#include <bits/stdc++.h>
#include <time.h>
#include <chrono>
#include <omp.h>

using namespace std::chrono;
using namespace std;
 

//matrix size
#define N 100

//declare variables
int matrix1[N][N];
int matrix2[N][N];
int result[N][N];

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
			cout << matrix[i][j] << ", ";
		cout << "\n";
	}
}

//main function
int main() 
{
    int i,j,k;

    //set number of threads to the number that available to the device
    omp_set_num_threads(omp_get_num_procs());
    initialize(matrix1, N, N);
    initialize(matrix2, N, N);

    //start time variable
    auto start = high_resolution_clock::now();
    
    // the multiply nested loop under omp directive with private i,j,k and shared matrix 1,2 and result
    #pragma omp parallel for private(i,j,k) shared(matrix1,matrix2,result)
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    //stop time variable
    auto stop = high_resolution_clock::now();

    //calculate the time taken by the function
    auto duration = duration_cast<microseconds>(stop - start);
    
    //print the result matrix
    print_matrix(result);
    //print time taken
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

}
