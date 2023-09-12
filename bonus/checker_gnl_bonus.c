/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:08:15 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 15:08:16 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_get_index(char *str, int c)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_add_buf_to_line(char *line, char c, int *read_error)
{
	int		line_len;
	char	*new_line;
	int		i;

	line_len = ft_strlen(line);
	if (c == '\0')
		return (NULL);
	new_line = malloc(sizeof(char) * (line_len + 2));
	if (!new_line)
	{
		*read_error = 1;
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i++] = c;
	new_line[i] = '\0';
	if (line)
		free(line);
	return (new_line);
}

static char	*ft_read_loop(int fd, char *line, int *read_error)
{
	char	buf;
	int		ret;

	ret = 1;
	while (ft_get_index(line, '\n') == -1 && ret != 0)
	{
		buf = '\0';
		ret = read(fd, &buf, 1);
		if (ret == -1)
		{
			*read_error = 1;
			return (ft_free_str(line), NULL);
		}
		line = ft_add_buf_to_line(line, buf, read_error);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd, int *op_error)
{
	char		*line;

	line = NULL;
	line = ft_read_loop(fd, line, op_error);
	if (!line)
		return (NULL);
	return (line);
}
