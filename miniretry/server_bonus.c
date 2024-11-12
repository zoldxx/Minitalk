/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:43 by dberreby          #+#    #+#             */
/*   Updated: 2023/04/13 14:47:43 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_len(int *len_received, char **str, int signal)
{
	static int	len = 0;

	if (*len_received == 1)
		return ;
	else if (*len_received == 2)
	{
		*len_received = 0;
		return ;
	}
	if (signal == SIGUSR1)
		len++;
	else if (signal == SIGUSR2)
	{
		*len_received = 1;
		*str = ft_calloc(len + 3, 1);
		if (!(*str))
			exit(0);
		len = 0;
	}
}

void	restart_variables(int *bit, char *i, int *len_received, int *k)
{
	*bit = 0;
	*i = 0;
	*len_received = 2;
	*k = 0;
}

void	printstr(char *c, char **str, int pid)
{
	kill(pid, SIGUSR2);
	*c = '\0';
	ft_printf("%s\n", *str);
	free(*str);
}

void	ft_handler(int signal, siginfo_t *pid, void *context)
{
	static int	bit = 0;
	static char	i = 0;
	static int	len_received = 0;
	static char	*str = NULL;
	static int	k = 0;

	(void) context;
	kill(pid->si_pid, SIGUSR1);
	if (len_received == 1)
	{
		if (signal == SIGUSR1)
			i |= (1 << bit);
		bit++;
		if (bit == 8 && i)
			tout_pour_la_norme(&bit, &i, &str[k], &k);
		else if (bit == 8 && !i)
		{
			printstr(&str[k], &str, pid->si_pid);
			restart_variables(&bit, &i, &len_received, &k);
		}
	}
	receive_len(&len_received, &str, signal);
}

// void	ft_handler(int signal, siginfo_t *pid, void *context)
// {
// 	static int	bit = 0;
// 	static char	i = 0;
// 	static int	len_received = 0;
// 	static char	*str = NULL;
// 	static int	k = 0;

// 	(void) context;
// 	kill(pid->si_pid, SIGUSR1);
// 	if (len_received == 1)
// 	{
// 		if (signal == SIGUSR1)
// 			i |= (1 << bit);
// 		bit++;
// 		if (bit == 8 && i)
// 		{
// 			str[k++] = i;
// 			bit = 0;
// 			i = 0;
// 		}
// 		else if (bit == 8 && !i)
// 		{
// 			printstr(&str[k], &str, pid->si_pid);
// 			restart_variables(&bit, &i, &len_received, &k);
// 		}
// 	}
// 	receive_len(&len_received, &str, signal);
// }

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("mauvais format\n");
		return (0);
	}
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
	}
	return (0);
}
