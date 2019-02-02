#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cassert>

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
        int time = atoi(pch);
        pch = strtok(NULL, DELIMIT);
        string fname = pch;
        pch = strtok(NULL, DELIMIT);
        string direction = pch;
        pch = strtok(NULL, DELIMIT);
        if (direction == "in")
        {
            cout << "< " << fname << "," << time << endl;
        }
        else if (direction == "out")
        {
            cout << "> " << fname << "," << time << endl;
        }
        else
        {
            assert(false);
        }
    }
    myfile.close();
    return 0;
}

