/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 05:47:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/04 07:16:23 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}



char	*get_next_line(int fd)
{	
	size_t	length;
	size_t	index;
	char	*buffer;
	char	*result;
	
	result = malloc(1000);
	index = 0;
	
	buffer = malloc(BUFFER_SIZE);
	length = read(fd, buffer, BUFFER_SIZE);
	if(!length)
		return (NULL);
	while(length)
	{
		ft_strlcpy(&result[index], buffer, length+1);
		index += length;
		if(ft_strchr(buffer, '\n'))
			return (result);
		length = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
