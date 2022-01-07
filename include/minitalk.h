/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:08:54 by habouiba          #+#    #+#             */
/*   Updated: 2022/01/07 11:10:49 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_byte {
	int	b1: 1;
	int	b2: 1;
	int	b3: 1;
	int	b4: 1;
	int	b5: 1;
	int	b6: 1;
	int	b7: 1;
	int	b8: 1;
}	t_byte;
#endif
