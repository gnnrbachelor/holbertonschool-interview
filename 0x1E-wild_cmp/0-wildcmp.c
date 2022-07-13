#include "holberton.h"

int wildcmp(char *s1, char *s2)
{

	if (!s1 || !s2)
		return (0);

	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		else if (*s2)
			return (0);
		return (1);
	}
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
