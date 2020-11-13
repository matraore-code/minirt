/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:53:16 by matraore          #+#    #+#             */
/*   Updated: 2020/11/13 04:47:13 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere_tools.h"

t_sphere new_sphere(double r, t_tuple pt)
{
    t_sphere sph;

    sph.origine = pt;
    sph.rayon = r;
    sph.id_u = id;
    id++;
    return (sph);
}
