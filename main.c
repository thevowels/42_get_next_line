/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 06:04:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/04 08:45:55 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd);

int main(void)
{
	int	fd;
	char *result;

	fd = open("main.c", O_RDONLY);

	while((result = get_next_line(fd)))
	{
		printf("%s", result);
		free(result);
		printf("\n---------------------\n");
	}
	printf("Buffer size: %d\n", BUFFER_SIZE);

	return (1);

}
