/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 05:47:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/08 03:45:15 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * @brief update the snl(string ,newline and length)
 * @param all pointer to snl
 * @param buffer string to concat to string of snl
 * @param buffer_length length of string stored in buffer
 *
 *
 *
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
	/*
	copy all the contents of old data into first part of new buffer
	for the first time when the str has only '\0' inside it
	We've to consider abut the s_l the length because when the length is 0
	there is stil '\0' inside the string
	*/
	if (all->s_l > 1)
	{
		tmp = all->str;
		while (i < (all->s_l))
		{
			update[i] = *(tmp++);
			i++;
		}
	}
	// copy the contents of the buffer to new buffer.
	i = 0;
	tmp = buffer;
	while (i < buffer_length)
	{
		if (*tmp == '\n')
			all->s_n = 1;
		update[i + all->s_l] = *(tmp++);
		i++;
	}
	update[i + all->s_l] = 0;
	free(all->str);
	//I add this because after free, the all->str become random value
	all->str = NULL;
	all->str = update;
	all->s_l += buffer_length;
}

char	*ft_strndup(char *s, ssize_t l)
{
	char	*all;
	int		i;

	i = 0;
	all = malloc(sizeof(char) * (l + 1));
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
	char	*line;
	char	*tmp;
	size_t	l;

	l = 0;
	tmp = all->str;
	while (*tmp != '\n' && l < all->s_l - 1)
	{
		tmp++;
		l++;
	}
	line = ft_strndup(all->str, l + 1);
	if (l == all->s_l - 1)
		tmp = ft_strdup("");
	else
		tmp = ft_strndup(all->str + l + 1, all->s_l - (l - 1));
	free(all->str);
	all->str = tmp;
	all->s_l -= (l + 1);
	l = 0;
	all->s_n = 0;
	while (l < all->s_l - 1)
	{
		if (tmp[l++] == '\n')
			all->s_n = 1;
	}
	// to delete later
	// free(all->str);
	// the all->str is need to be free when we reach to the final or if there is some error occured.
	return (line);
}
char	*get_next_line(int fd)
{
	char		*buffer;
	static snl	all;
	ssize_t		l;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(0, 0, 0) < 0)
		return (NULL);
	// This condition is run when we run the readline for the first time.
	if (!all.str)
	{
		// intialize all the parameters
		all.s_n = 0;
		all.s_l = 0;
		all.str = ft_strdup("");
		// allocate memory for buffer
		buffer = malloc((BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		/*
			Normally,
				I've too set the last position of buffer to \0 but I have the legth
			and I'm always gonna use that length along the program as I've to read binary files
		*/
		// we get the data, update the values.
		/*
		TODO: we need too think about a situation when we reach the end of the file.
			at that time, l will be 0.
		*/
		while(!all.s_n)
		{
			l = read(fd, buffer, BUFFER_SIZE);
			if(l < 0)
				return (NULL);
			buffer[l] = 0;
			ft_update_snl(&all, buffer, l);
		}
		free(buffer);
		buffer = NULL;
		return (next_line(&all));
	}
	/*
		This coondition is run form the second to last iterations.
		We've set the snl as static so it will maintian the data until the
		end of program execution.
	*/
	else
	{
		// ft_strlen(all) cannnot be used i'v'e to store the all_count;
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		l = 1;
		if (!all.s_n)
		{
			while (l > 0 || !all.s_n)
			{
				l = read(fd, buffer, BUFFER_SIZE);
				if (l < 0)
					return (NULL);
				buffer[l] = 0;
				ft_update_snl(&all, buffer, l);
			}
		}
		free(buffer);
		return (next_line(&all));
	}
	return (ft_strdup("asdfas"));
}
