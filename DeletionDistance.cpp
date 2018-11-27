#include <iostream>
#include <string>

using namespace std;

int deletionDistance( const string& str1, const string& str2 ) 
{
    int str1Len = str1.size();
    int str2Len = str2.size();

    int memo[str1Len+1][str2Len+1];

    for (int i = 0; i < str1Len; i++)
    {
        for (int j = 0; j < str2Len; j++)
        {
            if (i == 0)
                memo[i][j] = j;
            else if (j == 0)
                memo[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                memo[i][j] = memo[i-1][j-1];
            else
                memo[i][j] = 1 + min(memo[i-1][j], memo[i][j-1]);
        }
    }

    return memo[str1Len][str2Len];
}

int main()
{
    string str1 = "b";
    string str2 = "c";
    int d = deletionDistance(str1, str2);
    cout << "d of " << str1 << " and " << str2 << " is " << d << endl;
    return 0;
}

