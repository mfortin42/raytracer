/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:49:53 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/30 14:09:49 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_filebuffer	*get_filebuffer(int const fd, t_list *reminder)
{
	t_filebuffer			*filebuf;

	list_set_start(reminder);
	while ((filebuf = list_next(reminder)) != NULL)
		if (fd == filebuf->fd)
			return (filebuf);
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	filebuf = malloc(sizeof(t_filebuffer));
	filebuf->fd = fd;
	filebuf->stock = 0;
	filebuf->buffer = NULL;
	list_push_back(reminder, filebuf);
	return (filebuf);
}

char			*create_line(t_filebuffer *file, int length)
{
	char		*new_buffer;
	char		*str;

	str = ft_strnew(length);
	file->stock -= length + 1;
	ft_strncpy(str, file->buffer, length);
	new_buffer = ft_memjoin(NULL, file->buffer + length + 1, 0, file->stock);
	free(file->buffer);
	file->buffer = new_buffer;
	return (str);
}

int				read_file(t_filebuffer *f,
						t_list *reminder,
						char **line)
{
	int			read_ret;
	char		*end;
	char		*new_buffer;
	char		buffer[BUFF_SIZE + 1];

	end = "\0";
	while ((read_ret = read(f->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_ret] = '\0';
		new_buffer = ft_memjoin(f->buffer, buffer, f->stock, read_ret + 1);
		free(f->buffer);
		f->buffer = new_buffer;
		f->stock += read_ret;
		if (*(end = ft_strchrnul(f->buffer, '\n')) == '\n')
			break ;
	}
	if (read_ret == -1)
		return (-1);
	if (*end != '\n')
	{
		list_remove_value_inner(reminder, f, list_default_remove_functor);
		return (0);
	}
	*line = create_line(f, end - f->buffer);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	t_filebuffer	*file;
	char			*end;
	static t_list	reminder = { NULL, NULL, NULL, 0, 0 };

	if (fd < 0 || line == NULL)
		return (-1);
	if ((file = get_filebuffer(fd, &reminder)) == NULL)
		return (-1);
	if (file->stock > 0)
	{
		if (*(end = ft_strchrnul(file->buffer, '\n')) == '\n')
		{
			*line = create_line(file, end - file->buffer);
			return (1);
		}
	}
	return (read_file(file, &reminder, line));
}
