/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:55:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/10 15:45:38 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"
# include "rcontainers_lists.h"
# define BUFF_SIZE 4096

t_filebuffer	*get_filebuffer(int const fd, t_list *reminder);
char			*create_line(t_filebuffer *file, int length);
int				read_file(t_filebuffer *f, t_list *bufs, char **line);
int				get_next_line(int const fd, char **line);

#endif
