
/*
(a)    int a;                 // An integer
(b)    int *a;               // A pointer to an integer
(c)    int **a;             // A pointer to a pointer to an integer
(d)    int a[10];          // An array of 10 integers
(e)    int *a[10];        // An array of 10 pointers to integers
(f)     int (*a)[10];     // A pointer to an array of 10 integers
(g)    int (*a)(int);     // A pointer to a function a that takes an integer argument and returns an integer
(h)    int (*a[10])(int); // An array of 10 pointers to functions that take an integer argument and return an integer
*/

#include <iostream>

using namespace std;

int sqr(int in)
{
    return in*in;
}

int main()
{
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *b[10];
    int (*c)[10];
    c = &a;
    int (*d[10])(int);
    for (int i = 0; i < 10; i++)
    {
        d[i] = &sqr;
    }

    for (int i = 0; i < 10; i++)
    {
        a[i] = d[i]((*c)[i]);
        b[i] = &a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "a:" << a[i] << ", b:" << *b[i] << endl;
    }

    return 0;
}

