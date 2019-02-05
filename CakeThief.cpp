// https://www.interviewcake.com/question/python/cake-thief?
// cake_tuples = [(7, 160), (3, 90), (2, 15)]
// capacity    = 20
// answer = 555

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<pair<int, int> > tuple_data;

int solve_bag(tuple_data &tuples, int tuple_id, int cap, int **memo)
{
	if (tuple_id <= 0) return 0;
	if (cap <= 0) return 0;

	int memo_val = memo[tuple_id][cap];
	if (memo_val >= 0) 
		return memo_val;

	int weight = tuples.at(tuple_id).first;
	int value = tuples.at(tuple_id).second;
	int max_val = 0;
	for (int i = 0; i < cap / weight; i++)
	{
		int val = i * value + solve_bag(tuples, tuple_id - 1, cap - i * weight, memo);
		max_val = max(val, max_val);
	}
	memo[tuple_id][cap] = max_val;
	return max_val;
}

int max_duffel_bag_value(tuple_data &cake_tuples, int capacity)
{
	sort(cake_tuples.begin(), cake_tuples.end());
	int tuple_len = cake_tuples.size();
	int **memo = new int*[tuple_len];
    for (int i = 0; i < tuple_len; i++)
        memo[i] = new int[capacity];
	for (int i = 0; i < tuple_len; i++)
		for (int j = 0; j < capacity; j++)
			memo[i][j] = -1;
	return solve_bag(cake_tuples, tuple_len-1, capacity, memo);
    for (int i = 0; i < tuple_len; i++)
        delete[] memo[i];
    delete[] memo;
}

int main()
{
    tuple_data cake_tuples;
    cake_tuples.push_back(make_pair(7, 160));
    cake_tuples.push_back(make_pair(3, 90));
    cake_tuples.push_back(make_pair(2, 15));
    int capacity = 20;
    int res = max_duffel_bag_value(cake_tuples, capacity);

    cout << "result: " << res << endl;
    return 0;
}

