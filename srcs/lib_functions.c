/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:39:36 by acakste           #+#    #+#             */
/*   Updated: 2018/09/19 18:39:37 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
    int     i;

    if (s1 == NULL)
    {
        dup = ft_strdup("(null)");
        return (dup);
    }    
    dup = (char*)malloc(sizeof(char) * ft_strlen((char*)s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t  ft_strlen_wide(wchar_t *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

wchar_t	*ft_strdup_wide(wchar_t *s1)
{
	wchar_t	*dup;
    int     i;

    dup = (wchar_t*)malloc(sizeof(wchar_t) * ft_strlen_wide((wchar_t*)s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	new = (char*)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (*s1 != '\0')
			new[i] = *s1++;
		else
			new[i] = *s2++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
