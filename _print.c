#include <stdarg.h>
#include <unistd.h>
#include "main.h"
int _printf(const char *format, ...);
int _strlen(const char *str);
int print_number(int n);
/**
 * _printf - Printf propio
 * @format: formatos posibles del Printf
 *
 * Return: Numero de caracteres printeados
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;
	char *str_arg;
	char char_arg;

	va_start(args, format);

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			if (*(ptr + 1) == '\0')
			{
				return (-1);
			}

			if (*(ptr + 1) != '\0')
			{
				ptr++;

				switch (*ptr)
				{
					case 'c':
						char_arg = (char)va_arg(args, int);
						count += write(1, &char_arg, 1);
						break;
					case 's':
						str_arg = va_arg(args, char *);
					if (!str_arg)
					{
						count += write(1, "(null)", 6);
					}
					else
					{
						count += write(1, str_arg, _strlen(str_arg));
					}
						break;
					case 'd':
					case 'i':
						count += print_number(va_arg(args, int));
						break;
					case '%':
						count += write(1, "%", 1);
						break;
					default:
						count += write(1, "%", 1);
						count += write(1, ptr, 1);
						break;
				}
			}
		}

		else
		{
			count += write(1, ptr, 1);
		}
		ptr++;
	}

	va_end(args);
	return (count);
}

/**
 * _strlen - Recorre una string para saber su longitud
 * @str: string a ser recorrida
 * Return: longitud de la string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
/**
 * print_number - logica para printear numeros
 * @n: numero a ser printeado
 * Return: count
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;
	char digit;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}
	digit = '0' + num % 10;
	count += write(1, &digit, 1);

	return (count);
}
