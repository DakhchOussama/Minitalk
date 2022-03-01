/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:14 by odakhch           #+#    #+#             */
/*   Updated: 2022/02/25 16:06:34 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reset_data(t_data *data)
{
	data->c = 0;
	data->size = 0;
}

void	git_byte(int signum, siginfo_t *info, void *old_behavior)
{
	static t_data	data;
	static int		old_cpid;
	char			bs;
	static char		lc;

	bs = 8;
	data.client_pid = info->si_pid;
	if (data.client_pid != old_cpid)
	{
		if ((lc >> 8) & 1)
			write(1, &bs, 1);
		reset_data(&data);
		old_cpid = data.client_pid;
	}
	data.c += ((signum & 1) << data.size);
	if (data.size == 7)
	{
		ft_putchar(data.c);
		if (data.c == '\0')
			kill(info->si_pid, SIGUSR1);
		lc = data.c;
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
