/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:23:38 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/11/25 13:56:16 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*read_line(int fd, char **fd_save, char *read_buffer);
char	*read_runtime(int fd, char *res, char	*read_buffer);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# ifndef FD_LIMIT
#  define FD_LIMIT 256
# endif
#endif