#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
 
using namespace std;
 
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long llint;
 
class SkolemBinaryTree {
public:
  vector <int> construct(int k) {
    int l = 0, r = 1;
    vector<int> ans = {l, r};
    for (int i = 3; i <= k; i += 2) {
      int nl = 2*i - 2;
      int nr = 2*i - 1;
      ans.push_back(nl);
      ans.push_back(l);
      ans.push_back(nr);
      ans.push_back(r);
      l = nl, r = nr;
    }
 
    r = l;
    for (int i = 2; i <= k; i += 2) {
      int nl = 2*i - 2;
      int nr = 2*i - 1;
      ans.push_back(nl);
      ans.push_back(l);
      ans.push_back(nr);
      ans.push_back(r);
      l = nl, r = nr;
    }
 
    return ans;
  }
};

int main(int argc, char *argv[])
{
	SkolemBinaryTree sbt;
	vector<int> res = sbt.construct(atoi(argv[1]));
	for (vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
		    cout << *i << ' ';
	return 0;
}

