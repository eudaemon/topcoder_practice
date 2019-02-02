#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

#define DELIMIT " "

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
        char * pch;
        pch = strtok((char*)line.c_str(), DELIMIT);
        while (pch != NULL)
        {
            cout << pch << ",";
            pch = strtok(NULL, DELIMIT);
        }
        cout << endl;
    }
    myfile.close();
    return 0;
}

