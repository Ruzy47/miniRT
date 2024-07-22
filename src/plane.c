/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 15:44:38 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*new_plane(char *info)
{
	char		**tmp;
	char		**tmp2;
	t_plane		*obj;

	obj = malloc(sizeof(t_plane));
	if (!obj)
		err_exit(1);
	tmp = ft_split(info, ' ');
	tmp2 = ft_split(tmp[1], ',');
	obj->point = new_vec(my_atof(tmp2[0]), my_atof(tmp2[1]), \
		my_atof(tmp2[2]));
	doublefree(tmp2);
	tmp2 = ft_split(tmp[2], ',');
	obj->norm_vec = new_vec(my_atof(tmp2[0]), my_atof(tmp2[1]), \
		my_atof(tmp2[2]));
	vec_norm(obj->norm_vec);
	doublefree(tmp2);
	tmp2 = ft_split(tmp[3], ',');
	obj->color = ctoi(tmp2);
	doublefree(tmp2);
	doublefree(tmp);
	return (obj);
}
