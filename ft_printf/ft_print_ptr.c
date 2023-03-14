/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 16:30:36 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/06 11:20:46 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// %p The void * pointer argument has to be printed in hexadecimal format.

static int	ft_plen(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static	int	ft_to_ptr(uintptr_t n)
{
	uintptr_t	val;

	val = 0;
	if (n >= 16)
	{
		if (ft_to_ptr(n / 16) == -1)
			return (-1);
	}
	n = n % 16;
	if (n <= 9)
		val = ft_printchar((n + '0'));
	else
		val = ft_printchar((n - 10 + 'a'));
	return (val);
}

int	ft_print_ptr(unsigned long p)
{
	int	length;

	length = write(1, "0x", 2);
	if (length == -1)
		return (-1);
	if (p == 0)
		length += write(1, "0", 1);
	else
	{
		if (ft_to_ptr(p) == -1)
			return (-1);
		length += ft_plen(p);
	}
	return (length);
}
