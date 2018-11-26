
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void ReverseString(char *s)
{
    int sL = strlen(s);
    for (int i = 0; i < sL/2; i++)
    {
        char t = s[i];
        s[i] = s[sL-i-1];
        s[sL-i-1] = t;
    }
}

int main(int argc, char** argv)
{
    char t[128];

    sprintf(t, "Hello, world!");
    printf("%s\n", t);
    ReverseString(t);
    printf("%s\n", t);

    t[0] = 0;
    printf("%s\n", t);
    ReverseString(t);
    printf("%s\n", t);

    sprintf(t, "abc");
    printf("%s\n", t);
    ReverseString(t);
    printf("%s\n", t);
    return 0;
}

