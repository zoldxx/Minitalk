/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:17:41 by dberreby          #+#    #+#             */
/*   Updated: 2023/04/13 15:01:07 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	return (r * s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

void	tout_pour_la_norme(int *bit, char *i, char *str, int *k)
{
	*str = *i;
	*bit = 0;
	*i = 0;
	*k += 1;
}

void	ft_error(void)
{
	ft_printf("Error : wrong PID.\n");
	exit (0);
}
