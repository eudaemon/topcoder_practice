#include <vector>
#include <cassert>
#include <iostream>

#define VAL_NONE -1

using namespace std;

typedef vector<int> data_type;

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
		if (valNew == VAL_NONE)
		{
		data[valPrev] = valPrev;
		break;
		}
		valPrev = valNew;
		}
	}
	return VAL_NONE;
}

int main()
{
    data_type data = {2, 0, 1, 1};
    int ret = find_duplicate_from_linear_sequence(data);
    cout << "Duplicate: " << ret << endl;
}
