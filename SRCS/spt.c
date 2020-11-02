/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:30:55 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:45:36 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	to_v(t_ray *ray, int id)
{
	ray[id].f_v = 1;
	ray[id].v_wallhitx = ray[id].n_vtx;
	ray[id].v_wallhity = ray[id].n_vty;
}

void	to_h(t_ray *ray, int id)
{
	ray[id].f_h = 1;
	ray[id].h_wallhitx = ray[id].n_htx;
	ray[id].h_wallhity = ray[id].n_hty;
}

float	veta(float x, float y, float m, float n)
{
	return ((sqrt(((x - m) * (x - m)) + ((y - n) * (y - n)))));
}

void	min_value_ray(t_ray *ray, t_player player, int id)
{
	ray[id].was_v = 0;
	ray[id].horz_hitdis = (ray[id].f_h) ?
		veta(player.x, player.y, ray[id].h_wallhitx,
		ray[id].h_wallhity) : FLT_MAX;
	ray[id].vert_hitdis = (ray[id].f_v) ?
		veta(player.x, player.y, ray[id].v_wallhitx,
		ray[id].v_wallhity) : MAXFLOAT;
	ray[id].wallhitx = (ray[id].horz_hitdis < ray[id].vert_hitdis) ?
	ray[id].h_wallhitx : ray[id].v_wallhitx;
	ray[id].wallhity = (ray[id].horz_hitdis < ray[id].vert_hitdis) ?
	ray[id].h_wallhity : ray[id].v_wallhity;
	ray[id].distance = (ray[id].horz_hitdis < ray[id].vert_hitdis) ?
	ray[id].horz_hitdis : ray[id].vert_hitdis;
	ray[id].was_v = (ray[id].vert_hitdis < ray[id].horz_hitdis);
}
