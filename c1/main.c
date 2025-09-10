#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char * result;

	printf("Buffer size %i\n", BUFFER_SIZE);
	
	fd = open("abc", O_RDONLY);
	while(1)
	{
		result = get_next_line(fd);
		if(result)
		{
			printf("%s\n", result);
			free(result);
		}
		else
			break;
	}
	close(fd);
}