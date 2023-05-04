#include "main.h"
/**
 * print_int - prints integers
 * @i: integer
 * Return: 1
 */

int print_int(int i)
{
	unsigned int num;
	int count = 0;

	if (i < 0)
	{
		count += _putchar('-');
		num = i * -1;
	}
	else
	{
		num = i;
	}

	if (num >= 10)
		count += print_int(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * print_string - prints strings
 * @ap: list of arguments
 * Return: 1
 */

int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
