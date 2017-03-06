/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 18:26:32 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:25:26 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	progress_bar_init(t_interface *ui, t_vector2f resolution)
{
	t_vector4f remap;

	remap = m4f_mul_vector(ui->matrix, V4F_INIT(450, 35, 0, 0));
	ui->bar_bounding = element_new(ui, 0xFFFFFF, V2F_INIT((resolution.x / 2) -
						(remap.x / 2), (resolution.y / 2) - (remap.y / 2)),
						V2F_INIT(remap.x, remap.y));
	ui->bar_dynamic = element_new(ui, 0x00FF00, V2F_INIT((resolution.x / 2) -
						((remap.x - (remap.x / 35)) / 2), (resolution.y / 2) -
						((remap.y - (remap.y / 10)) / 2)), V2F_INIT(0, 0));
	ui->bar_dynamic_size = V2F_INIT(remap.x - (remap.x / 35),
									remap.y - (remap.y / 10));
	ui->bar_value = label_new_attach(ui, ui->bar_dynamic, "0%");
	progress_bar_show(ui, 0);
}

void	progress_bar_show(t_interface *ui, int val)
{
	ui->bar_bounding->active = val;
	ui->bar_dynamic->active = val;
	ui->bar_value->active = val;
}

void	progress_bar_update(t_interface *ui, int y, int y_max)
{
	int		width;
	float	percentage;
	char	*percentage_str;
	char	*percentage_join;

	percentage = (y * 100) / y_max;
	percentage_str = ft_itoa(percentage);
	percentage_join = ft_strjoin(percentage_str, "%");
	width = percentage * ui->bar_dynamic_size.x / 100;
	element_resize(ui->bar_dynamic, V2F_INIT(width, ui->bar_dynamic_size.y));
	label_update_text(ui->bar_value, percentage_join, V3F_INIT(0, 0, 0));
	free(percentage_str);
	free(percentage_join);
}
