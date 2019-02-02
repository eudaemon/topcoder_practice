#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cassert>
#include <unordered_map> 

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

    /** HashMap database for storing function name, starting time and
     * accumulated time usage.
     * first: starting time. If 'out' is declared, it will be negative.
     * second: accumulated time of function (out - in). */
    unordered_map<string, pair<int, int>> umap;
    unordered_map<string, pair<int, int>>::iterator itr; 

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
            // cout << "< " << fname << "," << time << endl;
            itr = umap.find(fname);
            if (itr == umap.end())
            {
                umap[fname] = make_pair(time,0);
            }
            else
            {
                assert(itr->second.first < 0);
                itr->second.first = time;
            }
        }
        else if (direction == "out")
        {
            // cout << "> " << fname << "," << time << endl;
            itr = umap.find(fname);
            assert(itr != umap.end());
            int startT = itr->second.first;
            assert(startT <= time);
            itr->second.second += time - startT;
            itr->second.first = -1;
        }
        else
        {
            assert(false);
        }
    }
    myfile.close();

    for (itr = umap.begin(); itr != umap.end(); itr++) 
    {
        cout << itr->first << ":" << itr->second.second << endl; 
        if (itr->second.first >= 0)
        {
            cout << "\t start time is not reset: " << itr->second.first << endl;
        }
    }     
    return 0;
}
