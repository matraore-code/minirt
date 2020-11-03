/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 03:26:20 by matraore          #+#    #+#             */
/*   Updated: 2020/11/03 10:36:19 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

#include "../tuples/tuples.h"

typedef struct canvas
{
    int width;
    int height;
    colorVec *pixels;
}t_canvas; 

t_canvas createCanvas(int w, int h);
t_canvas *write_pixel(t_canvas * canvas, int x, int y, colorVec color);
colorVec get_pixel(t_canvas *canvas, int x, int y);

#endif