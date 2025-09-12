/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:55:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/11 21:31:05 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strjoin(char const *s1, size_t m_len, char const *s2)
char	*ft_strjoin(t_data *data, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	data->m_len *= 2;
	res = malloc(sizeof(char) * (data->m_len));
	if (!res || !data->str || !s2)
		return (NULL);
	i = 0;
	while (data->str[i])
	{
		res[i] = data->str[i];
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

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	*str = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->str = str;
	data->s_len = 0;
	data->s_ncount = 0;
	data->m_len = BUFFER_SIZE + 1;
	return (data);
}
