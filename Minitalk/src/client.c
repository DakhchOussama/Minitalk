/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:48:25 by odakhch           #+#    #+#             */
/*   Updated: 2022/02/22 19:20:52 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, char *msg, size_t length)
{
	int	i;
	int	compteur;

	i = 0;
	while (i <= length)
	{
		compteur = 0;
		while (compteur <= 7)
		{
			if ((msg[i] >> compteur) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			compteur++;
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr("it's no same pid");
			return (0);
		}
		send_byte(pid, av[2], ft_strlen(av[2]));
	}
	else
	{
		ft_putstr("no msg to send\n");
	}
}
