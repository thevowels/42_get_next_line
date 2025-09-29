// asdf
#include "get_next_line_bonus.h"
#include "stdio.h"
int main(void)
{
	char *result;

	int fd1;
	int fd2;

	fd1 = open("main.c", O_RDONLY);

	// result = get_next_line(fd1);
	// printf("%s",result);
	// free(result);


	while(1)
	{
		result = get_next_line(fd1);
		if(result)
		{
			printf("%s", result);
			free(result);
		}
		else
			break;
	}
	while(1)
	{
		result = get_next_line(42);
		if(result)
		{
			printf("%s", result);
			free(result);
		}
		else
			break;
	}

	close(fd1);
	close(fd2);
}