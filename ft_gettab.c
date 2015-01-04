/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv->tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 18:14:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/02 22:39:31 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_nbcol(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] > ' ' && str[i + 1] <= ' ')
			nb++;
		i++;
	}
	return (nb);
}


t_pt3d	**ft_gettab(t_env *env, char *file, unsigned int *lin, unsigned int *col)
{
	int		fd;
	char	*line;
	unsigned int		i;
	unsigned int		j;

	*lin = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0) 
	{
		*col = ft_nbcol(line);
		*lin = *lin + 1;
	}
	close(fd);
	env->tab_origin = (t_pt3d **)malloc(sizeof(t_pt3d *) * (*lin + 1));
	env->tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * (*lin + 1));
	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		env->tab_origin[i] = (t_pt3d *)malloc(sizeof(t_pt3d) * (*col + 1));
		env->tab[i] = (t_pt3d *)malloc(sizeof(t_pt3d) * (*col + 1));
		j = 0;
		while (j < *col)
		{
			while (*line == ' ')
				line++;
			env->tab_origin[i][j].y = (float)i;
			env->tab_origin[i][j].x = (float)j;
			env->tab_origin[i][j].z = (float)ft_atoi(line);
			env->tab_origin[i][j].end = 0;
			line += ft_intlen(ft_atoi(line)) + 1;
			if (env->tab_origin[i][j].z < 0.0)
				line++;
			j++;
		}
		i++;
	}
	env->tab_origin[i] = NULL;
	env->tab[i] = NULL;
	return (env->tab_origin);
}
