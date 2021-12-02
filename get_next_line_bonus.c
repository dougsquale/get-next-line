/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:23:41 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/11/25 14:07:19 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*fd_saves[FD_LIMIT];
	char		*line;
	char		*read_buffer;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE < 1)
		return (NULL);
	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	if (!fd_saves[fd])
		fd_saves[fd] = ft_strdup("");
	line = read_line(fd, &fd_saves[fd], read_buffer);
	free(read_buffer);
	return (line);
}

char	*read_line(int fd, char **fd_save, char *read_buffer)
{
	char		*res;
	char		*nlpos;

	if (fd_save[fd])
	{
		res = ft_strdup(fd_save[fd]);
		fd_save[fd] = ft_strdup("");
		if (!fd_save[fd])
			return (NULL);
	}
	else
		res = ft_strdup("");
	if (!res)
		return (NULL);
	res = read_runtime(fd, res, read_buffer);
	if (!res)
		return (NULL);
	if (ft_strchr(res, '\n'))
	{
		nlpos = ft_strchr(res, '\n');
		fd_save[fd] = ft_substr(res, nlpos - res + 1,
				ft_strlen(res) - (nlpos - res));
		res = ft_substr(res, 0, nlpos - res + 1);
	}
	return (res);
}

char	*read_runtime(int fd, char *res, char	*read_buffer)
{
	int	chars_read;

	chars_read = BUFFER_SIZE;
	while (!ft_strchr(res, '\n') && chars_read == BUFFER_SIZE)
	{
		chars_read = read(fd, read_buffer, BUFFER_SIZE);
		if (*res && chars_read < 1)
			return (res);
		else if (chars_read < 1)
			return (NULL);
		read_buffer[chars_read] = 0;
		res = ft_strjoin(res, read_buffer);
	}
	return (res);
}
