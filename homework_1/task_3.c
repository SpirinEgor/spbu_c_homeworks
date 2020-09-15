#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int random(int a)
{
    return rand() % a;
}

int getpos(char a)
{
    if (a == ' ')
    {
        return 26;
    }
    return a - 'a' + 1;
}

int binpow(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 1)
    {
        return binpow(a, n - 1) * a;
    } else
    {
        int c = binpow(a, n / 2);
        return c * c;
    }
}

int hash(int a, int b, char str[], int prime_number)
{
    int i;
    int result = 0;
    for (i = a; i < b; i++)
    {
        result += binpow(prime_number, b - a - i - 1) * getpos(str[i]);
    }
    return result;
}

int search(char pattern[], char text[], int prime_number)
{
    int i;
    int n = 0;
    int pattern_length = strlen(pattern);
    int text_length = strlen(text);
    int pattern_hash = hash(0, pattern_length, pattern, prime_number);
    int buff_hash = hash(0, pattern_length, text, prime_number);
    for (i = 0; i < text_length - pattern_length + 1; i++)
    {
        if (buff_hash == pattern_hash)
        {
            int c = random(pattern_length);
            if (text[i + c] == pattern[c])
            {
                n++;
            }
        }
        buff_hash = prime_number * buff_hash - binpow(prime_number, pattern_length)
                                               * hash(i, i + 1, text, prime_number)
                    + hash(i + pattern_length, i + pattern_length + 1, text, prime_number);
    }
    return n;
}

int main()
{
    char s[1000];
    printf("%d", search("this", "this is a test", 13));
    return 0;
}

