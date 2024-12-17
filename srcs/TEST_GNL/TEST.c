
 #include "../lib/so_long.h"

// char	*get_next_line(int fd)
// {
// 	static char	*line = NULL;
// 	char		*return_line;

// 	if (fd < 0 || 64 <= 0 || read(fd, line, 0) < 0)
// 	{
// 		if (line != NULL)
// 		{
// 			free(line);
// 			line = NULL;
// 		}
// 		return (NULL);
// 	}
// 	line = get_line_fd(fd, line);
// 	if (ft_strlen(line) == 0)
// 	{
// 		free(line);
// 		line = NULL;
// 		return (line);
// 	}
// 	return_line = clean_line(line);
// 	line = get_remainder(line);
// 	return (return_line);
// }

// char	*get_line_fd(int fd, char *line)
// {
// 	char	*buffer;
// 	int		bytes_red;

// 	buffer = malloc((64 + 1) * sizeof(char));
// 	if (buffer == NULL)
// 		return (NULL);
// 	buffer[0] = '\0';
// 	bytes_red = 1;
// 	line = read_until_n(fd, line, buffer, bytes_red);
// 	return (line);
// }

// char	* read_until_n(int fd, char *line, char *buffer, int bytes_red)
// {
// 	char	*temp;

// 	while (ft_strchr(buffer, '\n') == NULL)
// 	{
// 		bytes_red = read(fd, buffer, 64);
// 		if (bytes_red == 0)
// 		{
// 			free(buffer);
// 			return (line);
// 		}
// 		buffer[bytes_red] = '\0';
// 		if (line == NULL)
// 			line = ft_strdup("");
// 		temp = line;
// 		if (temp != NULL && buffer != NULL)
// 			line = ft_strjoin(temp, buffer);
// 		free(temp);
// 	}
// 	free(buffer);
// 	return (line);
// }

// char	*clean_line(char *line)
// {
// 	int		i;
// 	char	*cleaned_line;

// 	i = 0;
// 	if (line != NULL)
// 	{
// 		while (line[i] != '\n' && line[i] != '\0')
// 			i++;
// 		cleaned_line = ft_substr(line, 0, i + 1);
// 		return (cleaned_line);
// 	}
// 	else
// 		return (NULL);
// }

// char	*get_remainder(char *line)
// {
// 	int		i;
// 	char	*remainder_line;

// 	i = 0;
// 	if (line != NULL)
// 	{
// 		while (line[i] != '\n' && line[i] != '\0')
// 			i++;
// 		remainder_line = ft_substr(line, i + 1, ft_strlen(line));
// 		free(line);
// 		line = NULL;
// 		return (remainder_line);
// 	}
// 	else
// 		return (NULL);
// }
// char	*ft_substr(char const *s_src, int start, int len)
// {
// 	char	*s_new;
// 	int	i;
// 	int	j;

// 	if (!s_src)
// 		return (NULL);
// 	if (start >= ft_strlen(s_src))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s_src) - start)
// 		len = ft_strlen(s_src) - start;
// 	s_new = malloc((len + 1)* sizeof(char));
// 	if (!s_new)
// 		return (NULL);
// 	i = start;
// 	j = 0;
// 	while (s_src[i])
// 	{
// 		if (j < len)
// 			s_new[j++] = s_src[i];
// 		i++;
// 	}
// 	s_new[j] = '\0';
// 	return (s_new);
// }