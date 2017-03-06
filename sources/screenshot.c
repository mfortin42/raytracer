/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:47:12 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:46:01 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

static void	tga_header(char *buffer, t_texture *tex)
{
	int i;

	i = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 2;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = 0;
	buffer[i++] = (tex->width & 0x00FF);
	buffer[i++] = (tex->width & 0xFF00) / 256;
	buffer[i++] = (tex->height & 0x00FF);
	buffer[i++] = (tex->height & 0xFF00) / 256;
	buffer[i++] = 24;
	buffer[i++] = 0;
}

static void	fill_image(char *buffer, t_texture *tex)
{
	int	pixel;
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			pixel = tex_get_pixel(tex, x, tex->height - y);
			buffer[i++] = (pixel >> 0) & 0xFF;
			buffer[i++] = (pixel >> 8) & 0xFF;
			buffer[i++] = (pixel >> 16) & 0xFF;
			x++;
		}
		y++;
	}
}

int			screenshot(t_core *core, char *name)
{
	int		fd;
	size_t	file_length;
	char	*filename;
	char	*buffer;

	if ((filename = get_valid_filename(name)) == NULL)
		return (0);
	if ((fd = open(filename, O_RDWR | O_CREAT, 0777)) < 0)
		return (0);
	file_length = 18 + (core->screen->width * core->screen->height * 3);
	buffer = (char *)malloc(file_length);
	tga_header(buffer, core->screen);
	fill_image(buffer + 18, core->screen);
	if (write(fd, buffer, file_length) < 0)
		return (0);
	close(fd);
	return (1);
}
