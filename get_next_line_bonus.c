/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:48:31 by lnicolof          #+#    #+#             */
/*   Updated: 2023/12/15 19:12:47 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_extract_line(char **stash, int *readed)
{
	char	*tmp;
	char	*cpy;
	int		i;

	if (!*stash && *readed == 0)
		return (NULL);
	tmp = *stash;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	cpy = ft_strdup(tmp, i);
	*stash = ft_strdup(tmp + i, ft_strlen(tmp + i));
	if (!tmp[i])
	{
		free(*stash);
		*stash = NULL;
	}
	if (tmp)
		free(tmp);
	tmp = NULL;
	return (cpy);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	int			readed;

	readed = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (readed > 0)
	{
		readed = read(fd, line, BUFFER_SIZE);
		line[readed] = '\0';
		stash[fd] = ft_strjoin(stash[fd], line);
		if (ft_strchr(stash[fd], '\n'))
			break ;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (ft_extract_line(&stash[fd], &readed));
}
