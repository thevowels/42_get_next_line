/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:24:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/11 00:02:02 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_size + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[total_size] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	check;

	check = (char)c;
	str = (char *)s;
	while (*str && *str != check)
	{
		str++;
	}
	if (check == *str)
		return (str);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size && count > ((size_t)-1) / size)
		return (NULL);
	size *= count;
	ptr = (void *)malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
