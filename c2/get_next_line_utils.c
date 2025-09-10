/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:55:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/11 02:06:27 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, size_t s1_l, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(sizeof(char) * (s1_l + ft_strlen(s2) + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	i = 0;
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
	res[i + j] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	check;

	str = (char *)s;
	check = (char)c;
	while (*str && check != *str)
	{
		str++;
	}
	if (check == *str)
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

t_data	*init_data(void)
{
	t_data	*data;
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	*str = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->str = str;
	data->s_len = 0;
	data->s_ncount = 0;
	return (data);
}
