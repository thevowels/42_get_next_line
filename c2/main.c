/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:13:44 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/12 21:45:50 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("abc", O_RDONLY);
	while (1)
	{
		result = get_next_line(fd);
		if (result)
		{
			printf("%s", result);
			free(result);
		}
		else
			break ;
	}
	close(fd);
}
