/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:06:08 by motanha-          #+#    #+#             */
/*   Updated: 2023/01/09 19:28:33 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	skip_space(int i, const char *nptr)
{
	while (nptr[i] == ' ' || \
			nptr[i] == '\t' || \
			nptr[i] == '\f' || \
			nptr[i] == '\n' || \
			nptr[i] == '\r' || \
			nptr[i] == '\v')
		i++;
	return (i);
}

static	int	get_sign(int i, const char *nptr)
{
	int	sign;

	sign = 1;
	if (nptr[i] == '-')
	{
		sign *= -1;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	if (nptr[i])
		i = skip_space(i, nptr);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = get_sign(i, nptr);
		i += 1;
	}
	result = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}
