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

#include <ft_printf.h>

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	sum;
	int		sign;

	i = 0;
	sum = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((((sum * 10) + (str[i] - 48)) - (str[i] - 48)) / 10 != sum)
			return ((sign == -1) ? 0 : -1);
		sum = (sum * 10) + (str[i] - 48);
		i++;
	}
	return (sum * sign);
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
