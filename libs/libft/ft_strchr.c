/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:04:17 by motanha-          #+#    #+#             */
/*   Updated: 2023/01/12 17:32:11 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	letter;
	char	*str;

	i = 0;
	letter = (char) c;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == letter)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && letter == '\0')
		return (str + i);
	return ((char *) NULL);
}
