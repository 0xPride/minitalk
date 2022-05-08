/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:09:06 by habouiba          #+#    #+#             */
/*   Updated: 2022/05/08 13:18:29 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	get_struct_field(t_byte *byte, int i)
{
	if (i == 0)
		return (byte->b1);
	if (i == 1)
		return (byte->b2);
	if (i == 2)
		return (byte->b3);
	if (i == 3)
		return (byte->b4);
	if (i == 4)
		return (byte->b5);
	if (i == 5)
		return (byte->b6);
	if (i == 6)
		return (byte->b7);
	if (i == 7)
		return (byte->b8);
	return (-1);
}

void	send_byte(t_byte *byte, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (get_struct_field(byte, i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		spid;
	int		i;
	t_byte	byte;

	if (argc != 3)
		return (0);
	spid = ft_atoi(argv[1]);
	ft_printf("Sending to : %i\n", spid);
	i = 0;
	while (argv[2][i])
	{
		*(unsigned char *)&byte = (unsigned char)argv[2][i];
		send_byte(&byte, spid);
		i++;
	}
}
