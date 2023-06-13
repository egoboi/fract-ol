/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:39:27 by fbrisson          #+#    #+#             */
/*   Updated: 2023/04/04 09:58:54 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_prog(char *error_msg)
{
	printf("%s", error_msg);
}

void	print_helper()
{
	printf("To make fract-ol proceed as : make <fractal_name>=mandel || julia || ship\n");
}
