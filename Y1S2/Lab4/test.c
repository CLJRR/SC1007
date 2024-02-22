#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[] = "Hello, world!";
    int i = 0;

    while (str[i])
    {
        putchar(toupper(str[i]));
        i++;
    }
    return 0;
}