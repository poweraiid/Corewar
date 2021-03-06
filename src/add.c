/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:19:16 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/27 19:02:57 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		add(t_env *p, t_proc *c)
{
	int		tmp;

	tmp = 0;
	if (get_00(p->mp[c->pc + 1].v) == 1 && get_01(p->mp[c->pc + 1].v)
	== 1 && get_02(p->mp[c->pc + 1].v) == 1)
	{
		if ((p->mp[c->pc + 2].v >= 1 && p->mp[c->pc + 2].v <= REG_NUMBER)
		&& (p->mp[c->pc + 3].v >= 1 && p->mp[c->pc + 3].v <= REG_NUMBER)
		&& (p->mp[c->pc + 4].v >= 1 && p->mp[c->pc + 4].v <= REG_NUMBER))
		{
			tmp = c->reg[p->mp[c->pc + 2].v] + c->reg[p->mp[c->pc + 3].v];
			c->carry = (tmp == 0) ? 1 : 0;
			c->reg[p->mp[c->pc + 4].v] = tmp;
		}
	}
	c->pc = (c->pc + 5) % MEM_SIZE;
}
