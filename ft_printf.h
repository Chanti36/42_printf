/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:42:41 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/10/18 10:01:47 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define MIN_HX "0123456789abcdef"
# define MAY_HX "0123456789ABCDEF"

int		write_char(char c);
int		write_str(char *str);
int		write_dec(long num);
int		use_val(char c, void *val);
int		ft_printf(const char *str, ...);
char	*int_to_hexa(size_t num, char *base);
int		write_hexa(size_t num, char *base);
int		putnbr(long num);
int		write_mem(void *p);

#endif