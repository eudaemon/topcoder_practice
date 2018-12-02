// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

#include <iostream>
using namespace std;

bool worker2(int trial, int ni, int mi, int n, int m, char *mat)
{
    int dat = mat[ni*m + mi];
    if (trial <= dat)
    {
        return true;
    }
    // split the target to 4 squares
    int trialS = trial / 2;
    if (!worker2(trialS, ni, mi, n, m, mat))
        return false;
    if (!worker2(trialS, ni + trialS, mi, n, m, mat))
        return false;
    if (!worker2(trialS, ni, mi + trialS, n, m, mat))
        return false;
    if (!worker2(trialS, ni + trialS, mi + trialS, n, m, mat))
        return false;
    // This means at least (ni,mi) has (trial & ~(0x01)) as a square
    mat[ni*m + mi] = min(dat, (trial & ~(0x01)));
    
    if (trial % 2)
    {
        // There is a remainder side bands to test.
        for (int i = 0; i < trial-1; i++)
        {
            if (mat[m*(ni+i) + mi + trial-1] == 0)
                return false;
            if (mat[m*(ni+trial-1) + mi + i] == 0)
                return false;
        }
        if (mat[m*(ni+trial-1) + mi+trial-1] == 0)
            return false;
    }
    mat[ni*m + mi] = trial;

    return true;
}

bool worker(int trial, int n, int m, char *mat)
{
    for (int ni = 0; ni+trial-1 < n; ni++)
    {
        for (int mi = 0; mi+trial-1 < m; mi++)
        {
            if (worker2(trial, ni, mi, n, m, mat))
                return true;
        }
    }
    return false;
}

int main() {
    int testNum;
    cin >> testNum;
    for (int testI = 0; testI < testNum; testI++)
    {
        int n, m, nm;
        cin >> n >> m;
        nm = n*m;
        // cout << "nm:" << nm << endl;
        char *mat = new char[nm]; 
        for (int i = 0; i < nm; i++)
        {
            int t;
            cin >> t;
            mat[i] = t;
        }
        // start from the maximum square size
        int trial = min(n, m);
        for (; trial > 0; trial--)
        {
            if (worker(trial, n, m, mat))
            {
                break;
            }
        }
        cout << trial << endl;
        delete[] mat;
    }
	return 0;
}
