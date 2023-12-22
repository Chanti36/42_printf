/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:04:32 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/10/18 09:57:34 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_to_hexa(size_t num, char *base)
{
	size_t	aux;
	int		i;
	char	*hexadecimalnum;

	i = 1;
	aux = num;
	while (aux >= 16)
	{
		aux /= 16;
		++i;
	}
	hexadecimalnum = (char *)malloc(sizeof(char) * (i + 1));
	if (!hexadecimalnum)
		return (NULL);
	hexadecimalnum[i--] = '\0';
	while (num != 0)
	{
		hexadecimalnum[i--] = base[num % 16];
		num /= 16;
	}
	return (hexadecimalnum);
}

int	write_hexa(size_t num, char *base)
{
	int	length;

	length = 1;
	if (num >= 16)
		length += write_hexa(num / 16, base);
	write_char(base[num % 16]);
	return (length);
}

int	putnbr(long num)
{
	int	length;

	length = 1;
	if (num > 9)
		length += putnbr(num / 10);
	write_char((num % 10) + '0');
	return (length);
}

int	write_mem(void *p)
{
	if (!p)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	return (write_hexa((unsigned long long)p, MIN_HX) + 2);
}
