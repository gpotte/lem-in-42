/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:21:17 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/11 17:09:02 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_env	env;
	t_room	room;

	parse_map(&env, &room);
//	do_pipe_struct(&env, &room);
//	resolve_path(&env);
//	move_ants(&env);
	return(0);
}
