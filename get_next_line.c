/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 05:47:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/06 00:03:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
	combine the old strings and buffer
	set the length accordingly.
*/
void	ft_update_snl(snl *all, char *buffer, size_t buffer_length)
{
	char	*update;
	char	*tmp;
	size_t	i;

	i = 0;
	update = malloc(all->s_l + buffer_length + 1);
	if (!update)
		return ;
	tmp = all->str;
	while (i < all->s_l)
	{
		update[i] = *(tmp++);
		i++;
	}
	i = 0;
	tmp = buffer;
	while (i < buffer_length)
	{
		update[i+all->s_l] = *(tmp++);
		i++;
	}
	update[i+all->s_l] = 0;
	free(all->str);
	free(buffer);
	all->str = update;
	all->s_l += buffer_length;
}

char	*ft_strndup(char *s, ssize_t l)
{
	char	*all;
	int		i;

	i = 0;
	all = malloc(sizeof(char) * (l+1));
	if (!all)
		return (NULL);
	while (i < l)
	{
		all[i] = s[i];
		i++;
	}
	all[i] = 0;
	return (all);
}

char	*next_line(snl *all)
{
	char *line;
	char * tmp;
	size_t	l;
	
	l = 0;
	tmp = all->str;
	while( *tmp != '\n')
	{
		tmp++;
		l++;
	}
	line = ft_strndup(all->str,l);

	tmp = ft_strndup(all->str+l, all->s_l - (l-1));
	free(all->str);
	all->str = tmp;
	all->s_l -= (l-1);
	return (line);
}
char	*get_next_line(int fd)
{
	char		*buffer;
	static snl	all;
	ssize_t		l;


	if (!all.str)
	{
		all.s_n = 0;
		all.s_l = 0;
		all.str = ft_strdup("");
		buffer = malloc((BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		l = read(fd, buffer, BUFFER_SIZE);
		ft_update_snl(&all, buffer, l);
		return next_line(&all);
	}
	else
	{
		// ft_strlen(all) cannnot be used i'v'e to store the all_count;
		if (ft_strchr(buffer, '\n'))
		{
			all.s_n = 1;
		}
		ft_update_snl(&all, buffer, l);
	}
	if (l > 0)
	{
		return(ft_strdup("abc"));
	}
	return (ft_strdup("asdfas"));
}
