/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:02:43 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 09:03:25 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;

	s_cpy = (char *)s;
	while (*s_cpy != (char)c && *s_cpy != '\0')
		s_cpy++;
	if (*s_cpy == (char)c)
		return (s_cpy);
	return (NULL);
}
