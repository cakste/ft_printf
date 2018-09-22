/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:09:16 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 11:09:17 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*s_ptr;
	size_t	len;
	size_t	i;

	s_ptr = (char *)s;
	if (!s_ptr)
		return (s_ptr);
	len = ft_strlen(s_ptr);
	new = (char*)malloc(sizeof(char) * len + 1);
	if (new)
	{
		i = 0;
		while (i < len)
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
