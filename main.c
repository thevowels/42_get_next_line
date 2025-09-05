/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 06:04:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/05 23:59:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

char	*get_next_line(int fd);

int main(void)
{
	int	fd;
	char *result;

	fd = open("main.c", O_RDONLY);
	
	result = get_next_line(fd);
	
	// int i = 0;
	// while(*result && i < 500)
	// {
	// 	printf("Char %i : ",i);
	// 	write(1, result,1);
	// 	write(1, "\n", 1);
	// 	result++;
	// 	i++;
	// }
	printf("%s\n", result);
	
	free(result);
	close(fd);
	return (0);

}
