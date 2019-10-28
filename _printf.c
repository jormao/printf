#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _printf - function my printf
 * @format: string whit format to print
 *
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	va_list args;
	spc_dt _types[] = {
		{"c", _print_a_char},
		{"s", _print_a_string},
		{NULL, NULL}
	};
	int i = 0, j = 0, count = 0;

	va_start(args, format);
	_evaluate(format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_write(format[i]);
			count += 1;
		}
		else
		{
			i++;
			while (_types[j].specifier)
			{
				if (*_types[j].specifier == format[i])
				{
					_types[j].f(args);
					count += 1;
				}
			j++;
			}
		j = 0;
		}
		i++;
	}
	return (count);
}
