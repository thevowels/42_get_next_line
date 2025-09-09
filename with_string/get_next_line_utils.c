/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:10:25 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/09 00:32:11 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == str[i])
		return (i);
	return (-1);
}

char	*ft_strndup(char *str, size_t t)
{
	char	*tmp;
	char	*result;

	tmp = ft_strdup( str + t);
	str[t] = 0;
	result = ft_strdup(str);
	free(str);
	str = tmp;
	return (result);

}

char	*ft_strdup(char *str)
{
	char *result;
	size_t l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	result = malloc(sizeof(char) * (l + 1));
	if (!result)
		return (NULL);
	l = 0;
	while (*str)
	{
		result[l] = *str;
		str++;
		l++;
	}
	result[l] = 0;
	return (result);
}