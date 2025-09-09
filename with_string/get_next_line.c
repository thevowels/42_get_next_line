/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:16:34 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/09 01:16:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str, char * result)
{
	size_t	i;
	char * tmp;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		i++;
	}
	result = ft_strndup(str, i);
	if(str[i] == 0)
		return ft_strdup("");
	return (ft_strdup(str+i));

}

static char *ft_concact_data(char *data, char *buffer, size_t b_l)
{
	char * tmp;
	size_t	s_l;
	size_t	i;

	s_l = 0;
	while(data[s_l])
		s_l++;
	tmp = malloc(sizeof(char) * (s_l + b_l + 1));
	if(!tmp)
	{
		free(data);
		return (NULL);
	}
	i = 0;
	while(i < s_l)
	{
		tmp[i] = data[i];
		i++;
	}
	i = 0;
	while(i < b_l)
	{
		tmp[i+s_l] = buffer[i];
		i++;
	}
	tmp[i+s_l] = 0;
	free(data);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char *data;
	char *buffer;
	char * result;
	size_t rc;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!data)
	{
		data = malloc(sizeof(char) * 1);
		data[0] = 0;

	}
	else if (ft_strchr(data, '\n') >= 0)
	{
		return (get_line(data, result));
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		rc = read(fd, buffer, BUFFER_SIZE);
		if (rc < 0)
		{
			free(buffer);
			return (NULL);
		}
		data = ft_concact_data(data, buffer, rc);
		if(ft_strchr(buffer, '\n') >= 0)
		{
			free(buffer);
			data = get_line(data, result);
			return (result);
		}
	}
	return (NULL);
}