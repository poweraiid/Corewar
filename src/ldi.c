/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:23:33 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/30 16:10:47 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		ldi(t_env *p, t_proc *c)
{
	int		adr1;
	int		adr2;
	int		adr3;
	int		tt;

	tt = 0;
	if ((get_00(p->mp[c->pc + 1].v) == 1 || get_00(p->mp[c->pc + 1].v) == 2
	|| get_00(p->mp[c->pc + 1].v) == 3) && (get_01(p->mp[c->pc + 1].v) == 1
	|| get_01(p->mp[c->pc + 1].v) == 2) && (get_02(p->mp[c->pc + 1].v) == 1))
	{
		tt = (get_00(p->mp[c->pc + 1].v) == 1) ? 2 : tt;
		tt = (get_00(p->mp[c->pc + 1].v) == 2) ? 3 : tt;
		tt = (get_00(p->mp[c->pc + 1].v) == 3) ? 3 : tt;
		adr3 = get_all(p, get_00(p->mp[c->pc + 1].v) + 3, c, 1);
		adr2 = get_all(p, get_01(p->mp[c->pc + 1].v) + 3, c, tt);
		adr1 = (adr3 + adr2) % IDX_MOD;
		tt = (get_01(p->mp[c->pc + 1].v) == 1) ? tt + 2 : tt;
		tt = (get_01(p->mp[c->pc + 1].v) == 2) ? tt + 3 : tt;
		tt = (get_01(p->mp[c->pc + 1].v) == 3) ? tt + 3 : tt;
		c->reg[p->mp[c->pc + tt].v] = get_all(p, 2, c, (adr1 % MEM_SIZE) - 1);
	}
	c->pc = c->pc + tt + 1;
}
