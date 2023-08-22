#include "main.h"

/**
 * _atoi - Convert a string to numbers
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
    (void)s; // Suppress the unused parameter warning

    int result = 0;
    int sign = 1;

    // Handle negative sign
    if (*s == '-')
    {
        sign = -1;
        s++;
    }

    // Convert characters to integer
    while (*s)
    {
        if (*s >= '0' && *s <= '9')
        {
            result = result * 10 + (*s - '0');
        }
        s++;
    }

    return result * sign;
}
