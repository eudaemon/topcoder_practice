
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int intersection_word_files(const char* fileA, const char* fileB)
{
    ifstream fA(fileA);
    if (!fA.is_open())
    {
        cerr << fileA << " cannot be opened." << endl;
        return -1;
    }
    ifstream fB(fileB);
    if (!fB.is_open())
    {
        cerr << fileB << " cannot be opened." << endl;
        fA.close();
        return -2;
    }
    // TODO: get the line size of each files and make the data of the smaller one.

    unordered_set<string> data;
    unordered_set<string>::iterator itr;

    string strLine;
    while (getline(fA, strLine))
    {
        itr = data.find(strLine);
        if (itr == data.end())
        {
            data.insert(strLine);
        }
    }
    while (getline(fB, strLine))
    {
        itr = data.find(strLine);
        if (itr != data.end())
        {
            cout << (*itr) << endl;
        }
    }
    return 0;
}

int main()
{
    const char *fileA = "wordListA.txt";
    const char *fileB = "wordListB.txt";
    return intersection_word_files(fileA, fileB);
}

