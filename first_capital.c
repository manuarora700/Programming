/*
 * C Program to find the First Capital Letter in a String without
 * using Recursion
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char caps_check(char *);

int main()
{
    char string[20], letter;

    printf("Enter a string to find it's first capital letter: ");
    scanf("%s", string);
    letter = caps_check(string);
    if (letter == 0)
    {
        printf("No capital letter is present in %s.\n", string);
    }
    else
    {
        printf("The first capital letter in %s is %c.\n", string, letter);    }
        return 0;
    }
    char caps_check(char *string)
    {
        int i = 0;
        while (string[i] != '\0')
        {
            if (isupper(string[i]))
            {
                return string[i];
            }
            i++;
        }
        return 0;
    }
