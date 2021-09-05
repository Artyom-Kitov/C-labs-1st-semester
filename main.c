#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int find(char *s, char *subs)
{
    int moves[512];
    for (int i = 0; i < 512; i++) moves[i] = strlen(subs);

    for (int i = 0; i < strlen(subs) - 1; i++) moves[subs[i]] = strlen(subs) - i - 1;
    
    int pos1 = strlen(subs) - 1;

    while (true)
    {
        int begin = pos1;

        int pos2 = strlen(subs) - 1;
        printf("%d ", pos1 + 1);
        while (pos2 >= 0 && s[pos1] == subs[pos2])
        {
            pos1--;
            pos2--;
            if (pos2 >= 0) printf("%d ", pos1 + 1);
        }
        if (pos2 < 0) return pos1 + 1;

        pos1 = begin + moves[s[begin]];
        if (pos1 >= strlen(s)) return -1;
    }
}

int main()
{
    char s[100]; gets(s);
    char subs[100]; gets(subs);

    int result = find(s, subs);

    printf("\n");
    return EXIT_SUCCESS;
}