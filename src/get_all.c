/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:25:19 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/30 16:10:50 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		get_all(t_env *p, int type, t_proc *c, int nbarg)
{
	if (type == 1 || type == 4)
		return (c->reg[p->mp[c->pc + nbarg + 1].v]);
	else if (type == 2)
		return (argint(p, c->pc + 1 + nbarg, 4));
	else if (type == 5)
		return (argint(p, c->pc + 1 + nbarg, 2));
	else if (type == 3 || type == 6)
		return (get_ind(argint(p, c->pc + 1 + nbarg, 2), p, c->pc, 4));
	return (-42);
}

int		get_all_all(t_env *p, int type, t_proc *c, int nbarg)
{
	if (type == 1 || type == 4)
		return (c->reg[p->mp[c->pc + nbarg + 1].v]);
	else if (type == 2)
		return (argint(p, c->pc + 1 + nbarg, 4));
	else if (type == 5)
		return (argint(p, c->pc + 1 + nbarg, 2));
	else if (type == 3 || type == 6)
		return (get_ind_all(argint(p, c->pc + 1 + nbarg, 2), p, c->pc, 4));
	return (-42);
}
