/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:10:35 by motanha-          #+#    #+#             */
/*   Updated: 2023/01/12 18:14:59 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		length;
	char	*large;
	char	*small;

	if (*little == '\0')
		return ((char *)big);
	large = (char *)big;
	small = (char *)little;
	i = 0;
	length = ft_strlen(small);
	while (large[i] != '\0' && (i + length) <= len)
	{
		if (ft_strncmp((large + i), small, length) == 0)
		{
			return (large + i);
		}
		i++;
	}
	return (NULL);
}
