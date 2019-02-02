#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Problem: Write a function that prints the common parts of string A and B. 
// (ex. cdhicdekefz, cdef => cd cde ef)
// (ex. cdefghij, klmncd => cd)

using namespace std;

int common_string(const string &a, const string &b, vector<string> &out, int min_len)
{
    int aL = a.size();
    int bL = b.size();
    for (int ia = -bL; ia < aL + bL; ia++)
    {
        int matchS = -1;
        int bTarget = min(bL, aL - ia);
        for (int ib = 0; ib < bTarget; ib++)
        {
            if (ia + ib < 0) continue;
            if (a.at(ia + ib) == b.at(ib))
            {
                if (matchS < 0)
                    matchS = ib;
            }
            else
            {
                if (matchS >= 0)
                {
                    if (ib - matchS >= min_len)
                        out.push_back(b.substr(matchS, ib - matchS));
                    matchS = -1;
                }
            }
        }
        if (matchS >= 0)
        {
            if (bTarget - matchS >= min_len)
                out.push_back(b.substr(matchS, bTarget - matchS));
        }
    } 
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cout << "Finds common substring between given two strings." << endl;
        cout << "usage: <exec> stringA, stringB, min_len" << endl;
        cout << "\t min_len: minimum length of common string" << endl;
        return 0;
    }
    vector<string> v;
    string a = argv[1];
    string b = argv[2];
    int min_len = atoi(argv[3]);
    common_string(a, b, v, min_len);

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
    return 0;
}
