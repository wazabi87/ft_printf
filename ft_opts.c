/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:31:41 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/27 19:31:03 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_opts2(char *tab, char **str, int i, char *opt)
{
	if (tab[0] == 1 && tab[1] == 1)
		i = ft_number(i, ft_atoi_base_printf((tab[3] == 1
			&& tab[4] == 1 ? (opt + 1) : opt), 10, 0), 1, str);
	else if (tab[1] == 1 && tab[0] == 0)
		i = ft_number(i, ft_atoi_base_printf((tab[3] == 1
			&& tab[4] == 1 ? (opt + 1) : opt), 10, 0), 0, str);
	if (tab[2] == 1)
	{
		if (opt[ft_strlen(opt) - 1] == 'o')
			i = ft_hastag(0, ' ', 0, str);
		else
			i = ft_hastag(0, ' ', 1, str);
	}
	if (tab[3] == 1)
		i = ft_plus(i, 0, 0, str);
	if (tab[4] == 1)
		i = ft_minus(i, 0, 0, str);
	return (i);
}

int		ft_opts(char *opt, char **str, int i)
{
	int		k;
	char	tab[5];

	printf("str = %s\n", *str);
	ft_bzero(tab, 5);
	k = ft_strlen(opt);
	while (k > 0 && --k)
	{
		while (k > -1 && ft_isdigit(opt[k]))
		{
			if (opt[k] == '0')
				if (k == 0 || !(ft_isdigit(opt[k - 1])))
					tab[0] = 1;
			tab[1] = 1;
			--k;
		}
		if (opt[k] == '#')
			tab[2] = 1;
		if (opt[k] == '+')
			tab[3] = 1;
		if (opt[k] == '-')
			tab[4] = 1;
	}
	return (ft_opts2(tab, str, i, opt));
}