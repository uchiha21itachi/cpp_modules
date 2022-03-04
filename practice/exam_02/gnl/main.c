#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char 		*line;
	
	fd = open("get_next_line.c", O_RDONLY);
//	fd = open("test00", O_RDONLY);
	if (fd < 0)
		printf("fd in main is wrong\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
