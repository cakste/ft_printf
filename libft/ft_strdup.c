/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:29:51 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 08:29:53 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char*)malloc(sizeof(char) * ft_strlen((char*)s1) + 1);
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, s1);
	return (dup);
}
