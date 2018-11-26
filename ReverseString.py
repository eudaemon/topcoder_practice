
def ReverseString(s):
    sL = len(s)
    for i in range(0,int(sL/2)):
        t = s[i]
        s[i] = s[sL-i-1]
        s[sL-i-1] = t

t = "Hello!"
print(ReverseString(t))
t = ''
print(ReverseString(t))
t = 'abc'
print(ReverseString(t))
t = 'Hi. Nice to meet you! :)'
print(ReverseString(t))

