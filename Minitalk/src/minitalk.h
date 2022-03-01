/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:03:13 by odakhch           #+#    #+#             */
/*   Updated: 2022/02/22 20:09:08 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_data
{
	char		c;
	size_t		size;
	int			client_pid;
}				t_data;

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	git_byte(int signum, siginfo_t *sit, void *old_behavior);
void	reset_data(t_data *data);
void	send_byte(int pid, char *msg, size_t length);

#endif
