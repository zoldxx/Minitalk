/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:14 by dberreby          #+#    #+#             */
/*   Updated: 2023/04/13 15:09:39 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_g;

void	boucle(void)
{
	while (g_g == 0)
	{
	}
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_g = 0;
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		boucle();
	}
}

void	count_char(int pid, char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		while (i > 0)
		{
			g_g = 0;
			kill(pid, SIGUSR1);
			i--;
			boucle();
		}
		g_g = 0;
		kill(pid, SIGUSR2);
		boucle();
	}
}

void	ft_handler(int signal, siginfo_t *pid, void *context)
{
	(void)pid;
	(void)context;
	if (signal == SIGUSR1)
		g_g = 1;
	else if (signal == SIGUSR2)
		exit(0);
}

int	main(int argc, char **av)
{
	int					pid;
	int					i;
	struct sigaction	so;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 1)
			ft_error();
		so.sa_sigaction = ft_handler;
		sigemptyset(&so.sa_mask);
		so.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &so, 0);
		count_char(pid, av[2]);
		while (av[2][++i] != '\0')
			ft_send_bits(pid, av[2][i]);
		sigaction(SIGUSR2, &so, 0);
		ft_send_bits(pid, '\0');
	}
	else
		ft_printf("Error: wrong format.\n");
	return (0);
}
