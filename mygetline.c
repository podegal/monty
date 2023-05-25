#include "monty.h"

/**
 * re_alloc - reallocate memory
 * @ptr: pointer to the variable need more space in memory
 * @length: initial length
 * @newlen: new length
 *
 * Return: the pointer tot he new space allocated
 */
void *re_alloc(void *ptr, size_t length, size_t newlen)
{
	void *newptr;

	if (!ptr)
		return (malloc(newlen));
	if (newlen == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (newlen == length)
		return (ptr);
	newptr = malloc(newlen);
	if (!newptr)
		return (NULL);
	if (newlen < length)
		memcpy(newptr, ptr, newlen);
	else
		memcpy(newptr, ptr, length);
	free(ptr);
	return (newptr);
}

/**
 * getLine - read a line from the stream
 * @lineptr: pointer to the line
 * @n: pointer tot the size of the buffer pointed by the line
 * @stream: stream from which the line will be readed
 *
 * Return: the number of character readed or -1 if failed
 */
ssize_t getLine(char **lineptr, size_t *n, FILE *stream)
{
	char buffer[128];

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = sizeof(buffer);
		*lineptr = malloc(*n);
		if (!(*lineptr))
			return (-1);
	}
	(*lineptr)[0] = '\0';
	while (fgets(buffer, sizeof(buffer), stream) != NULL)
	{
		if (*n - strlen(*lineptr) < sizeof(buffer))
		{
			*n *= 2;
			*lineptr = re_alloc(*line, *n / 2, *n);
			if (!(*lineptr))
			{
				free(lineptr);
				return (-1);
			}
		}
		strcat(*lineptr, buffer);
		if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
			return (strlen(*lineptr));
	}
	return (-1);
}
