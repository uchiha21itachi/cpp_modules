#include "get_next_line.h"
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while(str[i])
		i++;
	return (i);
}

char 	*ft_strdup(char *str)
{
	int	i = 0;
	char	*temp;
	int 	len;

	len = ft_strlen(str) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp == NULL)
	{
		// printf("malloc error in dup\n");
		return (NULL);
	}
	while(str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}	
char	*ft_strjoin(char *store, char *buf)
{
	int	i = 0;
	int	j = 0;
	char	*temp;
	int	len;

	if (!store || !buf)
	{
		// printf("returning from join\n");
		return (NULL);
	}
	len = ft_strlen(store) + ft_strlen(buf) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp == NULL)
	{
		// printf("Error in malloc in join");
		return (NULL);
	}
	while(store[i])
	{
		temp[j] = store[i];
		j++;
		i++;
	}
	i = 0;
	while(buf[i])
	{
		temp[j] = buf[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	free(store);
	return (temp);	
}


int		check_newline(char *str)
{
	int		i = 0;

	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_newline_pos(char *str)
{
	int		i = 0;

	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);

}

char	*read_line(char *store, int fd, int *ret)
{
	char		*buf;
	int			count;

	count = 1;
	if (check_newline(store))
		return (store);
	while(count != 0)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
		{
			free(store);
			return (NULL);
		}
		if ((count = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[count] = '\0';
		store = ft_strjoin(store, buf);
		free(buf);
		if (check_newline(store))
			return (store);	
	}
	if (count == 0)
		*ret = 1;
	return (store);
}

char	*ft_substr(char *str, int start, int end)
{
	int		size = 0;
	int		i = 0;
	char	*temp;

	if (end < start || !(str))
	{
		return (NULL);
	}
	size = (end - start) + 1;
	temp = (char *)malloc(sizeof(char) * size);
	if (temp == NULL)
		return (NULL);
	while(start < end)
	{
		temp[i] = str[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char 	*store;
	char			*line;
	char			*temp;
	int				ret;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 0)
	{
		return (NULL);
	}
	if (!store)
		store = ft_strdup("");
	ret = 0;

	store = read_line(store, fd, &ret);
	if(store == NULL)
		return (NULL);
	i = 0;

	while(store[i] != '\0' && store[i] != '\n')
		i++;
	if (store[0] == '\0' && ret == 1)
	{
		free(store);
		return (NULL);
	}
	if (store[i] == '\0')
	{
		line = ft_strdup(store);
		free(store);
		store = ft_strdup("");
		return (line);
	}
	line = ft_substr(store, 0, i+1);

	temp = store;
	store = ft_substr(temp, i+1, ft_strlen(store));
	free(temp);

	return (line);
}

int main(void)
{

	int	 fd;
	char	*line;

	fd = open("test04", O_RDONLY);	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
