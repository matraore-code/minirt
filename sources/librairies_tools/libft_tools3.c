/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:44:06 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:26:25 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/outils.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}
