/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:45:32 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/25 15:53:26 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print(char *str, int k)
{
	static int i;

	i = i + k;
	write(1, str, k);
	ft_bzero(str, k);
	return (i);
}