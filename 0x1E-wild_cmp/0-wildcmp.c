#include "holberton.h"

/**
 * str_len - the length of a string
 * @s: string
 * @n: the index
 * Return: the number of characters in a string.
 */
int str_len(char *s, int n)
{
	if (s[n] == '\0')
	{
		return (n);
	}
	return (str_len(s, n + 1));
}

/**
 * compare - Compares 2 strings
 * @s1: first string
 * @s2: second string
 * @i: index 1.
 * @j: index 2.
 * Return: 1 if the 2 strings' characters are identical, otherwise returns 0.
 */
int compare(char *s1, char *s2, int i, int j)
{
	int r = 0;

	if (!s1[i] && !s2[j])
		r = 1;
	else if (s2[j] != '*' && s1[i] != s2[j])
		r = 0;
	else if (s1[i] == s2[j])
		r = compare(s1, s2, ++i, ++j);
	else if (s2[j] == '*')
	{
		if (!s2[j + 1])
			r = 1;
		else if (s2[j + 1] && s2[j + 1] == '*')
			r = compare(s1, s2, i, ++j);
		else if (s2[j + 1] && s2[j + 1] == s1[i])
		{
			if (str_len(&(s2[j + 1]), 0) < str_len(&(s1[i]), 0))
				r = compare(s1, s2, ++i, j);
			else
				r = compare(s1, s2, i, ++j);
		}
		else if (s1[i + 1] && s2[j + 1])
		{
			if (s1[i + 1] != s2[j + 1])
				r = compare(s1, s2, ++i, j);
			else if (s1[i + 1] == s2[j + 1])
				r = compare(s1, s2, ++i, ++j);
		}
	}
	return (r);
}

/**
 * wildcmp - a function that compares two strings 
 * @s1: first string
 * @s2: second string
 * Return: 1 if the strings are identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{

	return (compare(s1, s2, 0, 0));
}