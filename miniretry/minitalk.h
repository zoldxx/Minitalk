/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:25:50 by dberreby          #+#    #+#             */
/*   Updated: 2023/04/13 15:01:17 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_atoi(char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	tout_pour_la_norme(int *bit, char *i, char *str, int *k);
void	ft_error(void);

#endif