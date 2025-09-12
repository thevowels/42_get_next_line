/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:01:40 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/13 00:22:35 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char			*str;
	size_t			s_ncount;
	size_t			s_len;
	size_t			m_len;
}					t_data;

typedef struct s_link
{
	int				fd;
	t_data			*data;
	struct s_link	*next;
}					t_link;

size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(t_data *data, char const *s2);
t_data				*init_data(void);
char				*get_next_line(int fd);
t_link				*init_link(void);

#endif
