/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:03:36 by motanha-          #+#    #+#             */
/*   Updated: 2023/01/12 18:05:29 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	return (i);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		i = 0;
		while (*str && (*str == c))
			str++;
		i = ft_wordlen(str, c);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_strdupp(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (j + 1));
	if (!dst)
		return (NULL);
	while (src[i] && i < j)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**ft_make_split(char const *s, char c, char **dest, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		j = ft_wordlen((char *)s, c);
		dest[i] = ft_strdupp((char *)s, j);
		if (!dest[i])
		{
			while (i > 0)
			{
				free(dest[i - 1]);
				i--;
			}
			free(dest);
			return (NULL);
		}
		s += j;
		i++;
	}
	dest[size] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		size;

	if (!s)
		return (NULL);
	size = ft_wordcount((char *)s, c);
	dest = malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	dest = ft_make_split(s, c, dest, size);
	return (dest);
}

/*static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}*/
