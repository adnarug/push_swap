#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s;
    s = malloc (sizeof(char) * 3);
    s[0] = "H";
    s[1] = "e";
    printf ("%s", s);
    system("leaks a.out");
    return (0);
}