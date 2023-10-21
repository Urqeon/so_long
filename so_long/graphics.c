/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulut <abulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:42:26 by abulut            #+#    #+#             */
/*   Updated: 2023/09/09 03:47:32 by abulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"

void	place_player(t_game *data, int height, int width)
{
	mlx_put_image_to_window(data->mlxpointer,
		data->winpointer, data->player, width * 120, height * 120);
	data->y_axis = height;
	data->x_axis = width;
}

void	place_collectable(t_game *data, int height, int width)
{
	mlx_put_image_to_window(data->mlxpointer,
		data->winpointer, data->collectable, width * 120, height * 120);
	data->collectables++;
}

void	images_in_game(t_game *data)
{
	int	i;
	int	j;

	data->floor = mlx_xpm_file_to_image(data->mlxpointer,
			"images/road.xpm", &i, &j);
	data->barrier = mlx_xpm_file_to_image(data->mlxpointer,
			"images/sea.xpm", &i, &j);
	data->player = mlx_xpm_file_to_image(data->mlxpointer,
			"images/player.xpm", &i, &j);
	data->exit = mlx_xpm_file_to_image(data->mlxpointer,
			"images/gate.xpm", &i, &j);
	data->collectable = mlx_xpm_file_to_image(data->mlxpointer,
			"images/worm.xpm", &i, &j);
}

void	adding_in_graphics(t_game *data)
{
	int	height;
	int	width;

	data->collectables = 0;
	height = -1;
	while (++height < data->map_height)
	{
		width = -1;
		while (data->map[height][++width])
		{
			if (data->map[height][width] == '1')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer, data->barrier, width * 120, height * 120);
			if (data->map[height][width] == 'C')
				place_collectable(data, height, width);
			if (data->map[height][width] == 'P')
				place_player(data, height, width);
			if (data->map[height][width] == 'E')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer, data->exit, width * 120, height * 120);
			if (data->map[height][width] == '0')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer, data->floor, width * 120, height * 120);
		}
	}
}
