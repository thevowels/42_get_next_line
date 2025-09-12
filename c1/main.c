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
		result = get_next_line(0);
		if(result)
		{
			printf("%s", result);
			free(result);
		}
		else
			break;
	}
	close(fd);
}
