/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:20:33 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/21 18:33:34 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	sti(t_env *p, t_proc *c)
{
	int		adr1;
	int		adr2;
	int		tt;

	tt = 0;
	if ((get_00(p->mp[c->pc + 1].v) == 1) && (get_01(p->mp[c->pc + 1].v) == 1
	|| get_01(p->mp[c->pc + 1].v) == 2 || get_01(p->mp[c->pc + 1].v) == 3)
	&& (get_02(p->mp[c->pc + 1].v) == 1 || get_02(p->mp[c->pc + 1].v) == 2))
	{
		tt = (get_01(p->mp[c->pc + 1].v) == 1) ? 3 : tt;
		tt = (get_01(p->mp[c->pc + 1].v) == 2) ? 4 : tt;
		tt = (get_01(p->mp[c->pc + 1].v) == 3) ? 4 : tt;
		adr1 = get_all(p, get_01(p->mp[c->pc + 1].v) + 3, c, 2);
		adr2 = get_all(p, get_02(p->mp[c->pc + 1].v) + 3, c, tt);
		p->mp[c->pc + (((adr1 + adr2) % IDX_MOD) % MEM_SIZE)].v = c->reg[p->mp[c->pc + 2].v];
		p->mp[c->pc + (((adr1 + adr2) % IDX_MOD) % MEM_SIZE)].players = c->nbdef;
		tt = (get_02(p->mp[c->pc + 1].v) == 1) ? tt + 2 : tt;
		tt = (get_02(p->mp[c->pc + 1].v) == 2) ? tt + 3 : tt;
		tt = (get_02(p->mp[c->pc + 1].v) == 3) ? tt + 3 : tt;
	//	ft_printf("ecrit a l'adresse %d, la valeur %d\n", c->pc + (((adr1 + adr2) % IDX_MOD)), c->reg[p->mp[c->pc + 2].v]);
	}
	c->pc = (c->pc + tt) % MEM_SIZE;
}
