/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:01:44 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/13 00:25:44 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_link *init_link(void)
{
	t_link *link;
	
	link = (t_link *) malloc(sizeof(t_link));
	if(!link)
		return(NULL);
	link->fd = -1;
	link->data = NULL;
	link->next = NULL;

	return link;
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
