/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:44:10 by matraore          #+#    #+#             */
/*   Updated: 2020/11/23 17:12:22 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RAYS_H
# define _RAYS_H

#include "stdio.h"
#include "stdlib.h"
#include "../matrices/matrices.h"
#include "../canvas/canvas.h"

static int id;



//the origine is a point and direction is a vector
typedef struct rays{
    t_tuple origine;
    t_tuple direction;  
}t_rays;


t_rays create_ray(t_tuple ori, t_tuple dir);
t_tuple position_point(t_rays r, double t);


#endif