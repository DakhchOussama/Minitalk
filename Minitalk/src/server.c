/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:45:49 by odakhch           #+#    #+#             */
/*   Updated: 2022/02/22 19:23:53 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_data(t_data *data)
{
	data->c = 0;
	data->size = 0;
}

void	git_byte(int signum, siginfo_t *info, void *old_behavior)
{
	struct t_data	data;
	static int		old_cip;

	data.client_pid = info->si_pid;
	if (data.client_pid != old_cip)
	{
		reset_data(&data);
		old_cip = data.client_pid;
	}
	data.c += ((signum & 1) << data.size);
	if (data.size == 7)
	{
		ft_putchar(data.c);
		reset_data(&data);
	}
	else
		data.size++;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &git_byte;
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
