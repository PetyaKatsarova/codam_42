/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 11:19:47 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/02 12:27:32 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int				ft_printchar(int c);
int				ft_printstr(char *str);
int				ft_printperc(void);
int				ft_print_num(int n);
int				ft_print_unsigned_int(unsigned int n);
unsigned int	ft_print_hex(unsigned int n, const char format);
int				ft_print_s(char *str);
int				ft_print_ptr(unsigned long p);
int				ft_printf(const char *format, ...);

#endif