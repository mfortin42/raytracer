/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 19:05:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/27 14:07:33 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	parse_error(char *str, int i)
{
	ft_putstr_fd("error : ", 2);
	ft_putstr_fd(str, 2);
	if (i != 0)
	{
		ft_putstr_fd(" line ", 2);
		ft_putnbr_fd(i, 2);
	}
	ft_putstr_fd(".\n", 2);
	exit(1);
}

void	ft_free_line_tab(char **str)
{
	char	*tmp;
	int		i;

	i = -1;
	while (str[++i])
	{
		tmp = str[i];
		free(tmp);
	}
	free(str);
}

int		ft_size_tab(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	ft_check_vcol(t_vector3f *col)
{
	col->x = clampf01(col->x);
	col->y = clampf01(col->y);
	col->z = clampf01(col->z);
}

char	*get_valid_filename(char *filename)
{
	int			fd;
	char		*nb;
	char		*full_file;
	char		*file_number;
	static int	number = 0;

	while (number >= 0)
	{
		nb = ft_itoa(number);
		file_number = ft_strjoin(filename, nb);
		free(nb);
		full_file = ft_strjoin(file_number, ".tga");
		free(file_number);
		if ((fd = open(full_file, O_RDONLY)) < 0)
			return (full_file);
		free(full_file);
		close(fd);
		number++;
	}
	return (NULL);
}
