/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/11 02:06:45 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	*str;
	size_t	s_ncount;
	size_t	s_len;
}			t_data;

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, size_t s1_l, char const *s2);
t_data		*init_data(void);
char		*get_next_line(int fd);

#endif