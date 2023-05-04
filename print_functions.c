#include "main.h"
/**
 * print_char - prints characters
 * @ap: list of arguments
 * Return: 1 (success)
 */

int print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);

	return (_putchar(c));
}

/**
 * printi - prints integers
 * @ap: list of arguments
 * Return: 1 (success)
 */

int printi(va_list ap)
{
	int i = va_arg(ap, int);

	return (print_int(i));
}


/**
 * int_to_binary - turns unsined int to binary
 * @num: unsigned int
 *
 * Return: 0 or 1
 */

int int_to_binary(int num)
{
	unsigned int count;

	count = 0;

	if (num / 2)
		count += int_to_binary(num / 2);

	count += _putchar((num % 2) + '0');

	return (count);
}

/**
 * int_to_bin - turns int to binary
 * @ap: list of arguments taken
 * Return: 1
 */

int int_to_bin(va_list ap)
{
	int a = va_arg(ap, int);

	return (int_to_binary(a));
}
