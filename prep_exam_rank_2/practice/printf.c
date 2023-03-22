/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 16:54:41 by arommers      #+#    #+#                 */
/*   Updated: 2023/03/06 17:00:03 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long long	n;
	int			len;

	len = 0;
	n = nb;
	if (n < 0)
	{
		len += write(1, "-", 1);
        n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_puthex(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16);
		len += ft_puthex(n % 16);
	}
	else if (n > 9)
		len += ft_putchar(n + 87);
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			len;
	va_list		ptr;

	i = 0;
	len = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 's')
				len += ft_putstr(va_arg(ptr, char *));
			else if (format[i] == 'x')
				len += ft_puthex(va_arg(ptr, unsigned int));
			else if (format[i] == 'd')
                len += ft_putnbr(va_arg(ptr, int));
		}
		else
		{
			if (format[i] != '%')
				len += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
