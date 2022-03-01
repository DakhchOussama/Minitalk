/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:05 by odakhch           #+#    #+#             */
/*   Updated: 2022/02/22 19:26:43 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_h(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("Message was received\n");
	exit(EXIT_SUCCESS);
}

void	send_byte(int pid, char *msg, size_t length)
{
	int		compteur;
	size_t	i;

	signal(SIGUSR1, sig_h);
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
	pause();
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr("ERROR");
		}
		send_byte(pid, av[2], ft_strlen(av[2]));
	}
	else
		ft_putstr("no msg to send\n");
}
