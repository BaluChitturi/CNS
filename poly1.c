#include <stdio.h>
#include <string.h>

int main()
{
    char map[26][26], c, ch;

    // Initialize the substitution map
    for (int i = 0, ch = 'a'; i < 26; i++, ch++)
    {
        for (int j = 0, c = ch; j < 26; j++, c++)
        {
            map[i][j] = c;
            if (c > 'z')
            {
                map[i][j] = c - 'z' + 'a' - 1;
            }
        }
    }

    char str[30], key[20];
    int n, m;

    printf("Enter string:\n");
    scanf("%s", str);

    printf("Enter key:\n");
    scanf("%s", key);

    int k = 0;
    while (strlen(key) != strlen(str))
    {
        key[strlen(key)] = key[k];
        k++;
    }

    for (int i = 0; i < strlen(str); i++)
    {
        n = m = 0;

        while (n + 'a' != str[i])
        {
            n++;
        }

        while (m + 'a' != key[i])
        {
            m++;
        }

        printf("%c", map[n % 26][m % 26]);
    }

    return 0;
}
