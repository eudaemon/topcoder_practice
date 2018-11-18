import sys

""" NextLuckyNumber
    Examples
    0)
    2048
    3
    0
    Returns: 3000
    The next number with exactly three zeros is 3000.
    2)
    9232425262
    2
    6
    Returns: 9232425266
    3)
    7
    1
    2
    Returns: 12
    4)
    76
    1
    7
    Returns: 78
    The next number with exactly one digit 7 is the number 78.
"""
class NextLuckyNumber:
    def getTicket(self, lastTicket, age, digit):
        x = lastTicket
        k = age
        d = digit

        res = sys.maxsize
        pp = 0
        p10 = 1
        while True:
            p10 *= 10
            pp += 1
            pref = x / p10
            mndig = pref % 10
            for dig in range(mndig+1, 10):
                # Do for loop
            if (p10 >= 1e17):
                break
        return res


nln = NextLuckyNumber()
print str(nln.getTicket(333, 7, 0))

