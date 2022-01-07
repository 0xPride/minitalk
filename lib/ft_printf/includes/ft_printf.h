/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:27:52 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/21 22:27:58 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define L_HEX "0123456789abcdef"
# define U_HEX "0123456789ABCDEF"
# define DECIMAL "0123456789"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
char	*ft_utoa(unsigned int n);
char	*ft_ultoa(unsigned long l_n);
char	*ft_ultoa_base(unsigned long long nbr, const char *base);
void	handle_char(t_list **lst, va_list ap);
void	handle_string(t_list **lst, va_list ap);
void	handle_decimal(t_list **lst, va_list ap);
void	handle_unsigned(t_list **lst, va_list ap);
void	handle_hex(t_list **lst, va_list ap, char c);
void	handle_ptr(t_list **lst, va_list ap);
void	handle_types(t_list **lst, va_list ap, const char *str, size_t i);
char	*char_dup(char c);
#endif
