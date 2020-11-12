/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:43:38 by matraore          #+#    #+#             */
/*   Updated: 2020/11/12 04:15:12 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_rays create_ray(t_tuple ori, t_tuple dir)
{
    t_rays r;

    r.origine = point(ori.x, ori.y, ori.z);
    r.direction = vector(dir.x, dir.y, dir.z);
    return (r);
}

t_tuple position_point(t_rays r, double t)
{
    t_tuple sum;
    t_tuple pos;

    pos =  multiTuples(t, r.direction);
    sum = sumTuples(r.origine, pos);
    return (sum);
}
