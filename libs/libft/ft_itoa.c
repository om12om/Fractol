/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:55:50 by motanha-          #+#    #+#             */
/*   Updated: 2023/01/12 18:12:34 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

static	int	ft_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

static	char	*ft_string(int n)
{
	char	*str;
	int		digits;

	digits = ft_digits(n);
	if (n < 0)
		str = malloc((digits + 2) * sizeof(char));
	else
		str = malloc((digits + 1) * sizeof(char));
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*str;
	int		a;

	a = n;
	str = ft_string(n);
	if (!str)
		return (NULL);
	length = 0;
	if (n == 0)
	{
		str[length++] = '0';
		str[length] = '\0';
		return (str);
	}
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (a < 0)
		str[length++] = '-';
		str[length] = '\0';
	ft_strrev(str);
	return (str);
}
