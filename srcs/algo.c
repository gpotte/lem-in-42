/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:34:59 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/23 11:43:26 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char **finding_path(t_env *env, t_room *room, char **path)
{
	int			i;
	t_room		*tmp;
	t_linkroom	*tmp_link;
	t_linkroom	*link_index;

	tmp = room;
	i = 0;
	path = (char **)malloc(sizeof(char *) * size_of_path(env, room) + 1);
	while (ft_strcmp(tmp->name, env->start))
		tmp = tmp->next;
	while (ft_strcmp(tmp->name, env->end))
	{
		path[i] = ft_strdup(tmp->name);
		tmp_link = tmp->link;
		link_index = tmp->link;
		while (link_index)
		{
			if (link_index->room->poid < tmp_link->room->poid)
				while (tmp_link->room->poid > link_index->room->poid)
					tmp_link = tmp_link->next;
			link_index = link_index->next;
		}
		tmp = tmp_link->room;
		i++;
	}
	path[i] = ft_strdup(tmp->name);
	path[i + 1] = NULL;
	return (path);
}

int		size_of_path(t_env *env, t_room *room)
{
	int			nb_coup;
	t_room		*tmp;
	t_linkroom	*link;
	t_linkroom	*index;

	nb_coup = 1;
	tmp = room;
	while (ft_strcmp(tmp->name, env->start))
		tmp = tmp->next;
	while (ft_strcmp(tmp->name, env->end))
	{
		link = tmp->link;
		index = tmp->link;
		while (index)
		{
			while (index->room->poid < link->room->poid)
				link = link->next;
			index = index->next;
		}
		tmp = link->room;
		nb_coup++;
	}
	return (nb_coup);
}