/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:10:21 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/11 21:31:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_updatedata(t_data *data, char *buffer)
{
	char	*tmp;
	size_t	l;

	l = data->s_len;
	if ((l + BUFFER_SIZE) > (BUFFER_SIZE * data->m_len - 1))
	{
		tmp = ft_strjoin(data, buffer);
		data->m_len +=1;
		free(data->str);
		data->str = tmp;
	}
	else
	{
		l = 0;
		while (buffer[l])
		{
			data->str[data->s_len + l] = buffer[l];
			l++;
		}
		buffer[l] = 0;
	}
	while (*buffer)
	{
		data->s_len += 1;
		if (*buffer == '\n')
			data->s_ncount += 1;
		buffer++;
	}
}

void	do_read(int fd, t_data *data)
{
	char	*buffer;
	ssize_t	byte_read;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[byte_read] = 0;
		ft_updatedata(data, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
}

char	*ft_getline(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	if (!*(data->str))
		return (NULL);
	while (data->str[i] && data->str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	line[i + 1] = 0;
	if (!line)
		return (NULL);
	i = 0;
	while (data->str[i] && data->str[i] != '\n')
	{
		line[i] = data->str[i];
		i++;
	}
	if (data->str[i] && data->str[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

t_data	*ft_clean(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (data->str[i] && data->str[i] != '\n')
		i++;
	if (!data->str[i])
	{
		free(data->str);
		free(data);
		return (NULL);
	}
	data->s_len -= (i + 1);
	data->m_len = (data->s_len / BUFFER_SIZE) + 1;
	tmp = malloc(sizeof(char) * (data->m_len * BUFFER_SIZE));
	i++;
	j = 0;
	while (data->str[i])
		tmp[j++] = data->str[i++];
	tmp[j] = 0;
	free(data->str);
	data->str = tmp;
	return (data);
}

char	*get_next_line(int fd)
{
	static t_data	*data;
	char			*line;

	if (!data)
		data = init_data();
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	do_read(fd, data);
	line = ft_getline(data);
	data = ft_clean(data);
	return (line);
}
