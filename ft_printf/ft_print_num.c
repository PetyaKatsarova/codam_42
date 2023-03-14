/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 18:05:24 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/02 11:25:59 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_num(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	if (num == NULL)
		return (-1);
	len = ft_printstr(num);
	free(num);
	return (len);
}
