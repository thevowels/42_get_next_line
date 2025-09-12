/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:10:21 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/13 00:30:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_updatedata(t_data *data, char *buffer)
{
	char	*tmp;
	size_t	l;

	if ((data->s_len + BUFFER_SIZE) >= data->m_len - 1)
	{
		tmp = ft_strjoin(data, buffer);
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
		data->str[data->s_len + l] = 0;
	}
	while (*buffer)
	{
		data->s_len += 1;
		if (*(buffer++) == '\n')
			data->s_ncount += 1;
	}
}

static void	do_read(int fd, t_data *data)
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

static char	*ft_getline(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	data->s_ncount -= 1;
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

static t_data	*ft_clean(t_data *data)
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
	tmp = malloc(sizeof(char) * (data->m_len));
	data->s_len -= (i + 1);
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
	static t_link	*llist;
	char			*line;
	t_link			*tmp_list;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

	if(!llist)
		llist = init_link();
	
	tmp_list = llist;

	while(tmp_list->fd != fd  && tmp_list->next != NULL)
		tmp_list = tmp_list->next;
	if(tmp_list->fd != fd)
	{
		tmp_list->next = init_link();
		tmp_list->next->fd = fd;
		tmp_list = tmp_list->next;
	}

	if(!tmp_list->data)
		tmp_list->data = init_data();

	if (!(tmp_list->data->s_ncount))
	{
		do_read(fd, tmp_list->data);
	}
	line = ft_getline(tmp_list->data);
	tmp_list->data = ft_clean(tmp_list->data);
	return (line);
}
