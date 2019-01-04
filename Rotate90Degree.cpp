
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

/** The dimention of the matrix. */
#define DIM     3

void print_matrix(int matrix[DIM][DIM], int dim)
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    int input[DIM][DIM];
    int temp = 0;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            input[i][j] = ++temp;
        }
    }
    print_matrix(input, DIM);

    // TODO: Rotate the input.
}

