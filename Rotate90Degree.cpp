
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

/** The dimention of the matrix. */
#define DIM    9 

void print_matrix(int matrix[DIM][DIM])
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

void rotate_matrix(int input[DIM][DIM], int output[DIM][DIM])
{
    for (int y = 0; y < DIM; y++)
    {
        for (int x = 0; x < DIM; x++)
        {
            int ind = y * DIM + x;
            int x2 = ind / DIM;
            int y2 = DIM-1 - (ind % DIM);
            output[y2][x2] = input[y][x];
        }
    }
}

int main(int argc, char** argv)
{
    int input [DIM][DIM];
    int output[DIM][DIM];
    int temp = 0;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            input[i][j] = ++temp;
        }
    }
    cout << "Input Matrix:" << endl;
    print_matrix(input);
    rotate_matrix(input, output);
    cout << "Output Matrix:" << endl;
    print_matrix(output);
}

