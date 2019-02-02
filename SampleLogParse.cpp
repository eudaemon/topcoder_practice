#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line;
    ifstream myfile("sample.log");
    if (!myfile.is_open())
    {
        cout << "Unable to open file";
        return 0;
    }

    while (getline(myfile,line))
    {
        cout << line << '\n';
    }
    myfile.close();
    return 0;
}

