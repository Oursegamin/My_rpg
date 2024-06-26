/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Task02
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len1 = 0;
    int len2 = 0;
    char *result = malloc(len1 + len2 + 1);
    int i;
    int j;

    if (!result || !dest || !src)
        return NULL;
    len1 = my_strlen(dest);
    len2 = my_strlen(src);
    for (i = 0; i < len1; i++)
        result[i] = dest[i];
    for (j = 0; j < len2; j++)
        result[i + j] = src[j];
    result[i + j] = '\0';
    return result;
}
