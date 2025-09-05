/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 05:51:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/05 20:44:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

typedef struct t_snl
{
	char	*str;
	size_t	s_l;
	char	s_n;
}			snl;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *b, size_t n);

#endif