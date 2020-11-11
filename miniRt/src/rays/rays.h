/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:44:10 by matraore          #+#    #+#             */
/*   Updated: 2020/11/11 06:45:03 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATRICES_H
# define _MATRICES_H

#include "stdio.h"
#include "stdlib.h"
#include "../matrices/matrices.h"
#include "../canvas/canvas.h"

static int id;

typedef struct rays{
    t_tuple origine;
    t_tuple direction;  
}t_rays;

#endif