/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:23:09 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/22 13:17:31 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*set_end_weight(t_env *env, t_room *room)
{
	t_room		*tmp;
	t_linkroom	*tmp2;

	tmp = room;
	tmp2 = room->link;
	while (ft_strcmp(tmp->name, env->end))
		tmp = tmp->next;
	env->weight = 1;
	tmp->poid = 1;
	env->poid_max = 1;
	return (room);
}

static t_room	*set_unlinked_room(t_env *env, t_room *room)
{
	t_room		*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->poid == -1)
			tmp->poid = env->poid_max + 1;
		tmp = tmp->next;
	}
	return (room);
}

t_room			*set_weights(t_env *env, t_room *room)
{
	t_room		*tmp;

	room = set_end_weight(env, room);
	while (env->weight < env->nb_room)
	{
		tmp = room;
		while (tmp)
		{
			if (!tmp->link && !tmp->poid)
			{
				env->weight++;
				tmp->poid = -1;
			}
			else if (!tmp->poid)
				tmp = set_weights2(env, tmp);
			tmp = tmp->next;
		}
		env->poid_max++;
	}
	room = set_unlinked_room(env, room);
	return (room);
}

t_room			*set_weights2(t_env *env, t_room *room)
{
	t_linkroom	*tmp;

	tmp = room->link;
	while (tmp && tmp->room->poid != env->poid_max)
		tmp = tmp->next;
	if (!tmp)
		return (room);
	room->poid = env->poid_max + 1;
	env->weight++;
	return (room);
}