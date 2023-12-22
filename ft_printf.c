/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:56:06 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/10/18 10:16:01 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char c)
{
	return (write(1, &c, 1));
}

int	write_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	write_dec(long num)
{
	if (num < 0)
	{
		num *= -1;
		write_char('-');
		return (putnbr(num) + 1);
	}
	return (putnbr(num));
}

int	use_val(char c, void *val)
{
	if (c == 'c')
		return (write_char((char)val));
	if (c == 's')
		return (write_str((char *)val));
	if (c == 'p')
		return (write_mem(val));
	if (c == 'd' || c == 'i')
		return (write_dec((int)val));
	if (c == 'u')
		return (write_dec((unsigned int)val));
	if (c == 'x')
		return (write_hexa((unsigned int)val, MIN_HX));
	if (c == 'X')
		return (write_hexa((unsigned int)val, MAY_HX));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		char_i;
	int		len;
	va_list	args;

	va_start(args, str);
	char_i = 0;
	len = 0;
	while (str[char_i])
	{
		if (str[char_i] == '%' && str[char_i + 1])
		{
			++char_i;
			if (str[char_i] == '%')
				len += write_char(str[char_i]);
			else
				len += use_val(str[char_i], va_arg(args, void *));
		}
		else
			len += write_char(str[char_i]);
		++char_i;
	}
	return (len);
}
