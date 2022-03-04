#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int 	i;
	char 	*temp;
	int	len;

	i = 0;
	len = ft_strlen(str) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp == NULL)
	{
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

char	*ft_strjoin(char *str1, char *str2)
{
	int 	len;
	char 	*temp;
	int	i;
	int	j;
	//should check for null?
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while(str1[i])
	{
		temp[j] = str1[i];
		j++;
		i++;
	}
	i = 0;
	while (str2[i])
	{
		temp[j] = str2[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

int	check_errors(int fd, char **storage)
{
	if (!*storage)
	{
		*storage = ft_strdup("");
	}
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
	{
		return (-1);
	}
	return (0);
}	

int	check_newline(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_newline(char *storage, int pos)
{
	char 	*temp;
	int	i;
	
	i = 0;
	temp = (char *)malloc(sizeof(char) * (pos + 2));
	if (temp == NULL)
	{
		printf("malloc error");
		return (NULL);
	}
	while(storage[i] != '\n' && storage[i] != '\0')
	{
		temp[i] = storage[i];
		i++;
	}
	if (storage[i] != '\0' && storage[i] == '\n')
	{
		temp[i] = storage[i];
		i++;
	}
	temp[i] = '\0';
		
	return (temp);
}

char	*update_storage(char *storage, int pos)
{
	int 	i;
	int	j;
	int	size;
	char	*temp;

	i = pos;
	j = 0;
	size = ft_strlen(storage) - (pos);
	temp = (char *)malloc(sizeof(char) * (size));
	if (temp == NULL)
	{
		printf("malloc error\n");
		return (NULL);
	}
	while(storage[++i] != '\0')
	{
		temp[j] = storage[i];
		j++;
	}
	temp[j] = '\0';
	free(storage);
	return (temp);
}


char	*read_file(int fd, char *storage, int *main_ret)
{
	
	// char	buf[BUFFER_SIZE + 1];
	char	*buf;
	int	ret;
	char	*temp;
	int	nl_ret;
	
	nl_ret = -2;
	nl_ret = check_newline(storage);
	if (nl_ret >= 0)
		return (storage);
	nl_ret = -2;
	
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
	{
		printf("Null returned here\n");
		if (storage)
			free(storage);
		return (NULL);
	}
	
	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = storage;
		storage = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
		nl_ret = check_newline(storage);
		if (nl_ret >= 0)
		{
			return (storage);
		}	
	}
	if (buf)
		free(buf);
	if (ret <= 0)
	{
		*main_ret = 1;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	
	char 		*line;
	static char 	*storage;
	int		nl_check;
	int		ret;


	line = NULL;
	ret = 0;

	if (check_errors(fd, &storage) == -1)
	{
		printf("Error returning 01\n");
		if (storage)
			free(storage);
		return (line);
	}
	storage = read_file(fd, storage, &ret);
	if (storage == NULL)
		return (NULL);
	nl_check = check_newline(storage);
	if (nl_check >= 0)
	{
		line = get_newline(storage, nl_check);
		storage = update_storage(storage, nl_check);
	}
	if (ret == 1 && check_newline(storage) < 0)
	{
		free(storage);
	}
	return (line);
}

//What to do if buffer is neg
