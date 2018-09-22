/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 05:58:10 by acakste           #+#    #+#             */
/*   Updated: 2018/09/22 11:22:09 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/*
**	Checks to see if we have any carryover from last buffer read. Continue to
**	read until you read a '\n' into the buffer, or you finish the file (bytes
**	read would be zero).
*/

char	*ft_readline(t_list *trav)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes_read;
	char	*del;
	char	*rest;

	rest = (trav->content) ? ft_strdup(trav->content) : ft_strdup("");
	if (!ft_strchr(rest, '\n'))
	{
		while ((bytes_read = read(trav->content_size, buff, BUFF_SIZE)))
		{
			if (bytes_read == -1)
				return (NULL);
			buff[bytes_read] = '\0';
			del = rest;
			rest = ft_strjoin(rest, buff);
			free(del);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	}
	return (rest);
}

/*
**	Finds the first item in the list with the correct file descriptor. If
**	none are found, it creates a new listelement with the data.
*/

t_list	*ft_find_lstitem(t_list **start, const int fd)
{
	t_list	*trav;

	trav = *start;
	while (trav && trav->content_size != (size_t)fd)
		trav = trav->next;
	if (trav == NULL)
	{
		ft_lstadd(start, ft_lstnew("", fd));
		trav = *start;
	}
	return (trav);
}

/*
**	Return faulty pointers. Find lstitem, read line. Break case
**	If the rest (read string) has newline, cut it up until the newline.
**	Else, you have read to end of file. Dup everything. Save the carryover.
**	If there is a newline, duplicate from one char after that. Else, set
**	carryover (trav->content) to NULL for break.
*/

int		get_next_line(const int fd, char **line)
{
	static t_list	*start = NULL;
	t_list			*trav;
	char			*rest;

	if (fd < 0)
		return (-1);
	trav = ft_find_lstitem(&start, fd);
	rest = ft_readline(trav);
	if (rest == NULL || *rest == '\0')
	{
		ft_lstdel(&start, &ft_del);
		return ((rest == NULL) ? -1 : 0);
	}
	free(trav->content);
	*line = (ft_strchr(rest, '\n')) ? ft_strsub(rest, 0, (ft_strchr(rest, '\n')
		- rest)) : ft_strdup(rest);
	trav->content = (ft_strchr(rest, '\n')) ? ft_strdup(1 + ft_strchr(rest,
		'\n')) : NULL;
	free(rest);
	return (1);
}
