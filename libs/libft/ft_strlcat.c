/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:34 by motanha-          #+#    #+#             */
/*   Updated: 2023/01/12 17:34:35 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*csrc;
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	res;

	csrc = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	res = 0;
	if (size > len_dst)
		res = len_dst + len_src;
	else
		res = size + len_src;
	i = 0;
	while (csrc[i] != '\0' && (len_dst + 1) < size)
	{
		dst[len_dst] = csrc[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
}
