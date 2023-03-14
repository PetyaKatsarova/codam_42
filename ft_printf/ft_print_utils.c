/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 17:26:25 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/16 12:35:58 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printchar(int c)
{
	return (write(1, &c, sizeof(char)));
}

int	ft_printperc(void)
{
	return (write(1, "%", 1));
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	else
	{
		i = ft_strlen(str);
		if (write(1, str, i) == -1)
			return (-1);
	}
	return (i);
}

int	ft_num_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
