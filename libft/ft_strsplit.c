/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:21:13 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 14:21:16 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	sub_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static size_t	count_words(char const *s, char c, size_t words, size_t is_c)
{
	if (*s == '\0')
		return (words);
	if (is_c)
	{
		while (*s == c)
			s++;
		return (count_words(s, c, words, 0));
	}
	else
	{
		while (*s != c && *s != '\0')
			s++;
		words++;
		return (count_words(s, c, words, 1));
	}
}

static char		**populate_tab(char **tab, size_t words, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words)
	{
		if (s[i] != c)
		{
			len = sub_len(&s[i], c);
			tab[j] = ft_strsub(&s[i], (unsigned int)0, len);
			if (!(tab[j]))
				return (NULL);
			i += len;
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = 0;
	words = count_words(s, c, words, 1);
	tab = (char**)malloc(sizeof(char*) * (words) + 1);
	if (!tab)
		return (NULL);
	tab = populate_tab(tab, words, s, c);
	return (tab);
}
