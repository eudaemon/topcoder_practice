#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long double ld;
 
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 
#define sz(x) ((int) (x).size())
#define TASK "text"
 
const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);
 
mt19937 mrand(random_device{} ()); 
 
int rnd(int x) {
  return mrand() % x;
}
 
int getCnt(long long x, int d) {
  int res = 0;
  while(x) {
    int cur = x % 10;
    x /= 10;
    if (cur == d) {
      res++;
    }
  }
  return res;
}
 
struct NextLuckyNumber
{
  long long getTicket(long long x, int k, int d)
  {
    long long res = infll;
    // Current index working on
    int pp = 0;
    for (long long p10 = 1;; p10 *= 10, pp++) {
      long long pref = x / p10;
      int mndig = pref % 10;
      // Since the ticket is looking for next one start from mndig + 1
      for (int dig = mndig + 1; dig < 10; dig++)
      {
        // Current candidate of possible ticket
        long long cur = pref;
        cur -= cur % 10;
        cur += dig;
        int have = getCnt(cur, d);
        int need = k - have;
        // If have is less than age and need is less than index processed
        // Note that we have power over pp we have.
        if (have <= k && need <= pp)
        {
          if (d == 0)
          {
            // Set the end need digits to 0
            for (int i = 0; i < need; i++)
            {
              cur = cur * 10;
            }
            // Fill the rest of them to 1
            for (int i = 0; i < pp - need; i++)
            {
              cur = cur * 10 + 1;
            }
          }
          else
          {
            // Multiply to resume the size of original x
            for (int i = 0; i < pp - need; i++)
            {
              cur = cur * 10;
            }
            // Set the end need digits to d
            for (int i = 0; i < need; i++)
            {
              cur = cur * 10 + d;
            }
          }
          // res gets the lowest of possible tickets
          res = min(res, cur);
        }
      }
      // When it's too big. Stop
      if (p10 == (long long) 1e17) break;
    }
    return res;
  }
};

int main()
{
	NextLuckyNumber nln;
	long long nT = nln.getTicket(76, 1, 7);
	printf("nT = %lld\n", nT);
	return 0;
}
