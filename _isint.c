#include "monty.h"

/**
 * @brief
 *
 */

bool _isint(char *buffer)
{
    int i;

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (!((buffer[i] - '0') >= 0 && buffer[i] <= '9'))
        {
            return (false);
        }
    }


    return true;
}