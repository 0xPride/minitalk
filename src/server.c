/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:09:13 by habouiba          #+#    #+#             */
/*   Updated: 2022/01/07 13:07:14 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	set_struct_field(t_byte *byte, int i, int bit)
{
	if (i == 0)
		byte->b1 = bit;
	if (i == 1)
		byte->b2 = bit;
	if (i == 2)
		byte->b3 = bit;
	if (i == 3)
		byte->b4 = bit;
	if (i == 4)
		byte->b5 = bit;
	if (i == 5)
		byte->b6 = bit;
	if (i == 6)
		byte->b7 = bit;
	if (i == 7)
		byte->b8 = bit;
}

t_byte	byte;

void sigusr_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("1");
	else if (sig == SIGUSR1)
		ft_printf("0");
}

int	main(void)
{
	struct sigaction	act;
	int			pid;


	ft_bzero(&act, sizeof(act));
	ft_bzero(&byte, sizeof(byte));
	act.sa_handler = &sigusr_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	pid = getpid();
	ft_printf("%i\n", pid);
	while (1)
	{
		pause();
	}
}
