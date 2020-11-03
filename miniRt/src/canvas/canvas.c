/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 03:34:19 by matraore          #+#    #+#             */
/*   Updated: 2020/11/03 10:36:23 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include <stdlib.h>

t_canvas createCanvas(int w, int h)
{
    t_canvas can;

    can.width = w;
    can.height = h;
    can.pixels = ft_calloc(w*h*sizeof(colorVec), 3);
    return (can);
}

t_canvas *write_pixel(t_canvas *canvas, int x, int y, colorVec color)
{
    
    if ((x >= 0 && x < canvas->width)  && (y >= 0 && y < canvas->height))
    {
        colorVec *addr =  (colorVec*)canvas->pixels + sizeof(colorVec)*y*x + sizeof(colorVec)*y;
        addr->red = color.red;
        addr->green = color.green; 
        addr->blue = color.blue;
        
        return (canvas);
    }
    return (0);
}

colorVec get_pixel(t_canvas *canvas, int x, int y)
{
    colorVec *addr = (colorVec*)canvas->pixels + sizeof(colorVec)*x*y + sizeof(colorVec)*y;
    return (*addr);
}