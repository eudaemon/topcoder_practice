
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define INPUT_FILE "data.txt"

int main () {
    string line;
    ifstream myfile (INPUT_FILE);
    if (!myfile.is_open())
    {
        cout << "Unable to open input file: " << INPUT_FILE << endl;
        return 0;
    }

    int sum = 0;
    while ( getline (myfile,line) )
    {
        try
        {
            int r = stoi(line);
            // cout << r << '\n';
            sum += r;
        }
        catch (exception e)
        {
        }
    }
    myfile.close();
    cout << "sum: " << sum << '\n';

    return 0;
}

