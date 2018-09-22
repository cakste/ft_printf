/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:04:26 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 14:04:28 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	endspaces;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	endspaces = 0;
	while (s[i] != '\0')
	{
		endspaces = (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') ?
		endspaces + 1 : 0;
		i++;
	}
	new = (char*)malloc(sizeof(char) * (i - start - endspaces) + 1);
	if (new)
	{
		new = ft_strncpy(new, &s[start], (i - start - endspaces));
		new[i - start - endspaces] = '\0';
	}
	return (new);
}
