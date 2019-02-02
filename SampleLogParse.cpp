#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>

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
        cout << time << "," << fname << "," << direction << endl;
    }
    myfile.close();
    return 0;
}

