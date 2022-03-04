#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	check_newline(char *str)
{
	int i = 0;

	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	int	i;
	int	len;
	char	*temp;

	i = 0;
	len = ft_strlen(str) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp == NULL)
		return (NULL);
	while(str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);	
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*temp;
	int	i;
	int	j;
	int	size;

	if(!(str) || !(buf))
		return (NULL);
	size = ft_strlen(str) + ft_strlen(buf) + 1;
	temp = (char *)malloc(sizeof(char) * size);
	if (temp == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	j = 0;
	while(str[i])
	{
		temp[j] = str[i];
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
	free(str);
	return (temp);
}

char	*ft_substr(char *str, int start, int end)
{
	int	size;
	char	*temp;
	int	i = 0;
	
	if (end < start)
		return (NULL);
	if (!(str))
		return (NULL);

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

char	*read_line(char *str, int fd, int *ret)
{
	char 	*buf;
	int	count;

	if(check_newline(str) == 1)
		return (str);
	count = 1;
	while(count != 0)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
		{
			free(str);
			return (NULL);
		}
		if ( (count = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[count] = '\0';
		str = ft_strjoin(str, buf);
		free(buf);
		if (check_newline(str) == 1)
			return (str);
	}
	if (count == 0)
		*ret = 1;
	return (str);

}

char	*get_next_line(int fd)
{
	static char	*store;
	int		ret;
	int		i;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!(store))
	{
		store = ft_strdup("");
		if (store == NULL)
			return (NULL);
	}
	ret = 0;
	store = read_line(store, fd, &ret);
	if (store == NULL)
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
	return(line);
}














