/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:28:13 by dberreby          #+#    #+#             */
/*   Updated: 2023/04/10 17:51:18 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	lennbr(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar('0' + n);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (lennbr(n));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6))
			return (6);
		return (0);
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int	convert(va_list set, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(set, int));
	if (c == 's')
		i = ft_putstr(va_arg(set, char *));
	if (c == 'd')
		i = ft_putnbr(va_arg(set, unsigned int));
	if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	setting;
	int		compteur;
	int		i;

	va_start(setting, s);
	compteur = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			compteur += convert(setting, s[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			compteur++;
		}
		i++;
	}
	va_end(setting);
	return (compteur);
}
