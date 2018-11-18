import sys

if len(sys.argv) < 3:
    print "Usage: starting number, target number"
    sys.exit(1)

class ReverseAndIncrease:
    def reverse(self, k):
        return int(str(k)[::-1])

    def find_min(self, k):
        a = str(k)
        # Check from the end character if it is better to increase.
        aL = len(a)
        # print("aL=" + str(aL))
        for i in range(aL-1, 1):
            l = int(a[i-1])
            r = int(a[i])
            if l < r:
                a[i] = str(l+1)[0]
                a[i+1] = '1'
        return int(a[::-1])

    def isPossible(self, s, t):
        k = s
        if t >= k:
            return "Possible"
        k = self.find_min(k)
        if t >= k:
            return "Possible"
        return "Impossible"

rai = ReverseAndIncrease()
print rai.isPossible(int(sys.argv[1]), int(sys.argv[2]))
 
