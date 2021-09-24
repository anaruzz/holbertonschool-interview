#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

/**
 * compare - compares two strings
 * @first: first string
 * @second: second string
 * Return: 1 if the strings can be considered identical, otherwise return 0
**/

int compare(const char *first, const char *second)
{

	if (*first == '\0' && *second == '\0')
		return (1);

	if (*first == '*' && *(first + 1) != '\0' && *second == '\0')
		return (0);

	if (*first == '.' || *first == '?' ||  *first == *second)
		return (compare(first + 1, second + 1));

	if (*first == '*')
		return (compare(first + 1, second) || compare(first, second + 1));
	return (0);
}

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int regex_match(char const *str, char const *pattern)
{
    return (compare(pattern, str));
}