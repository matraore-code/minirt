/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:33:45 by matraore          #+#    #+#             */
/*   Updated: 2021/01/26 15:10:26 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tuple.h"
#include <stdio.h>

t_tuple     check_cross(t_tuple right, t_tuple cam_vector)
{
    t_tuple forward;
    
    forward = create_tuple(0, 1, 0);
	normalize_vector(&forward);
	right = cross_product(forward, cam_vector);
    if(right.x == 0 && right.y == 0 && right.z == 0)
    {
        forward = create_tuple(1, 1, 1);
        normalize_vector(&forward);
        right = cross_product(forward, cam_vector);
        normalize_vector(&right);
        return (right);
    }
    normalize_vector(&right);
    return (right);
}

t_matrix	look_at(t_tuple origin, t_tuple cam_vector)
{
	t_matrix	m;
	t_tuple		right;
	t_tuple		up;

    right = check_cross(right, cam_vector);
	up = cross_product(cam_vector, right);
	normalize_vector(&up);
	m.d[0][0] = right.x;
	m.d[0][1] = right.y;
	m.d[0][2] = right.z;
	m.d[1][0] = up.x;
	m.d[1][1] = up.y;
	m.d[1][2] = up.z;
	m.d[2][0] = cam_vector.x;
	m.d[2][1] = cam_vector.y;
	m.d[2][2] = cam_vector.z;
	m.d[3][0] = origin.x;
	m.d[3][1] = origin.y;
	m.d[3][2] = origin.z;
	return (m);
}