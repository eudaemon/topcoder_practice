#include <vector>
#include <cassert>
#include <iostream>
#include <numeric>
#include <algorithm>

#define VAL_NONE -1

using namespace std;

typedef vector<int> data_type;

void print_data(data_type &data)
{
    int iLen = data.size();
    cout << "[";
    for (int i = 0; i < iLen; i++)
    {
        cout << data[i] << ",";
    }
    cout << "]" << endl;
}

int find_duplicate_from_linear_sequence(data_type &data)
{
    int iLen = data.size();
    for (int i = 0; i < iLen; i++)
    {
        int valPrev = data[i];
        if (valPrev == i || valPrev == VAL_NONE) continue;
        data[i] = VAL_NONE;

        for (;;)
        {
            assert(valPrev >= 0);
            int valNew = data[valPrev];
            if (valNew == valPrev)
            {
                // We found the duplicate.
                return valNew;
            }
            data[valPrev] = valPrev;
            if (valNew == VAL_NONE)
            {
                // We reached the end of this inner loop.
                break;
            }
            valPrev = valNew;
        }
    }
    return VAL_NONE;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Returns a random duplicate in the randomly shuffled array in O(N) time." << endl;
        cout << "usage: <executable> <array_size>" << endl;
        return 0;
    }

    srand(time(NULL));
    int data_max = atoi(argv[1]);

    data_type data(data_max);
    iota(begin(data), end(data), 0);
    int answer = rand() % data_max;
    data.push_back(answer);
    random_shuffle(data.begin(), data.end());
    // print_data(data);

    int ret = find_duplicate_from_linear_sequence(data);
    cout << "Duplicate Calculated: " << ret << endl;
    cout << "Duplicate Answer: " << answer << endl;
    assert(ret == answer);
    return 0;
}
