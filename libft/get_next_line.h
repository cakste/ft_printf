/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 05:58:19 by acakste           #+#    #+#             */
/*   Updated: 2018/09/22 11:22:26 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 150
# include <unistd.h>
# include "libft.h"

typedef	struct	s_line_list
{
	char				*str;
	int					fd;
	struct s_line_list	*next;
}				t_line_list;

int				get_next_line(const int fd, char **line);

#endif
