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
            ptr++;
            switch (*ptr)
            {
                case 'c':
                    char_arg = (char)va_arg(args, int);
                    count += write(1, &char_arg, 1);
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    count += write(1, str_arg, _strlen(str_arg));
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
        else
        {
            count += write(1, ptr, 1);
        }
        ptr++;
    }
    va_end(args);
    return (count);
}

int _strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
      {
        len++;
      }
    return (len);
}

int print_number(int n)
{
    int count = 0;
    unsigned int num;

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

    count += write(1, "0" + num % 10, 1);

    return (count);
}
