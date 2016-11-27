/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobecontinued.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:16:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/27 11:13:26 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_number(int k, int i, int bool, char **str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*str);
	if (len < i)
		tmp = malloc(i + 1);
	else
		return (k);
	tmp = ft_memset(tmp, (bool == 1 ? '0' : ' '), i - len);
	tmp[i - len] = '\0';
	ft_strcat(tmp + i - len, *str);
	free(*str);
	*str = tmp;
	return (i);
}

int		ft_plus(int k, int i, int bool, char **str)
{
	char *tmp;

	i = bool;
	if (ft_isdigit((*str)[0]))
	{
		tmp = malloc(k + 2);
		tmp = ft_memset(tmp, '\0', 2);
		ft_strcat(tmp + 1, *str);
		tmp[0] = '+';
		free(*str);
		*str = tmp;
		return (k + 1);
	}
	return (k);
}

int		ft_minus(int k, int i, int bool, char **str)
{
	char *tmp;

	i = bool;
	while ((*str)[i] == ' ' || (*str)[i] == '0')
		++i;
	tmp = malloc(k + 1);
	*tmp = 0;
	tmp[k] = 0;
	tmp = ft_strcat(tmp, *str + i);
	free(*str);
	*str = tmp;
	while (i--)
		(*str)[i + ft_strlen(tmp)] = ' ';
	return (k);
}

int		ft_hastag(int k, int i, int bool, char **str)
{
	char *tmp;

	if (bool == 0)
	{
		tmp = *str;
		free(*str);
		str = malloc(ft_strlen(tmp) * sizeof(char) + 2);
		(*str)[0] = '0';
		while (tmp[i++])
			(*str)[i + 1] = tmp[i];
		(*str)[i + 1] = '\0';
	}
	else
	{
		tmp = *str;
		free(*str);
		str = malloc(ft_strlen(tmp) * sizeof(char) + 3);
		(*str)[0] = '0';
		(*str)[1] = 'x';
		while (tmp[i++])
			(*str)[i + 2] = tmp[i];
		(*str)[i + 2] = '\0';
	}
	free(tmp);
	return (k);
}