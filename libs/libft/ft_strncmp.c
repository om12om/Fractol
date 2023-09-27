/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:09:31 by motanha-          #+#    #+#             */
/*   Updated: 2023/01/12 18:22:02 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	if (n == 0)
		return (0);
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while (cs1[i] != '\0' && cs2[i] != '\0' && i < n - 1)
	{
		if (cs1[i] != cs2[i])
		{
			return (cs1[i] - cs2[i]);
		}
		i++;
	}
	return (cs1[i] - cs2[i]);
}
