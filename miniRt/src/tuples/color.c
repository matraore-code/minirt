/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:59:53 by matraore          #+#    #+#             */
/*   Updated: 2020/11/03 01:36:45 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

colorVec color(float red, float green, float blue)
{
    colorVec c;

    c.red = red;
    c.green = green;
    c.blue = blue;
    return (c);
}

colorVec addingColor(colorVec c, colorVec d)
{
    return (color(c.red + d.red, c.green + d.green, c.blue + d.blue));
}

colorVec subColor(colorVec c, colorVec d)
{
    return (color(c.red - d.red, c.green - d.green, c.blue - d.blue));
}

colorVec multipColor(colorVec c, colorVec d)
{
    return (color(c.red * d.red, c.green * d.green, c.blue * d.blue));
}


colorVec scalarColor(float c, colorVec d)
{
    return (color(c * d.red, c * d.green, c * d.blue));
}