#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int 	fd;
	char 	*line;
	

	fd = open("test03" ,O_RDONLY);
	while( (line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	(void)fd;
	return (0);
}
