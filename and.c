/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:30:50 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/08 19:30:48 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void		and(t_env *p, t_proc *c)
{
	int		tmp;
	int		tt;

	if ((get_00(p->mp[c->pc + 1].v) == 1 || get_00(p->mp[c->pc + 1].v) == 2
	|| get_00(p->mp[c->pc + 1].v) == 3) && (get_01(p->mp[c->pc + 1].v) == 1
	|| get_01(p->mp[c->pc + 1].v) == 2 || get_01(p->mp[c->pc + 1].v) == 3)
	&& (get_02(p->mp[c->pc + 1].v) == 1))
	{
		tt = (get_00(p->mp[c->pc + 1].v) == 1) ? 2 : tt;
		tt = (get_00(p->mp[c->pc + 1].v) == 2) ? 5 : tt;
		tt = (get_00(p->mp[c->pc + 1].v) == 3) ? 3 : tt;
		tmp = get_all(p, get_00(p->mp[c->pc + 1].v), c, 1)
		& get_all(p, get_01(p->mp[c->pc + 1].v), c, tt);
		c->reg[p->mp[c->pc + 4].v] = tmp;
		c->carry = ((get_00(p->mp[c->pc + 1].v) == 1 && p->mp[c->pc + 2].v >= 1
		&& p->mp[c->pc + 2].v <= REG_NUMBER) || (get_01(p->mp[c->pc + tt].v)
		== 1 && p->mp[c->pc + tt].v >= 1
		&& p->mp[c->pc + tt].v <= REG_NUMBER)) ? 1 : 0;
	}
	else
		c->carry = 0;
	ft_printf("%d & %d = %d, attendu = %d carry = %d\n", get_all(p, get_00(p->mp[c->pc + 1].v), c, 1), get_all(p, get_01(p->mp[c->pc + 1].v), c, 2), tmp, 2 & 2 , c->carry);
	tmp = 0;
	tmp = (get_01(p->mp[c->pc + 1].v) == 1) ? tmp + 1 : tmp;
	tmp = (get_00(p->mp[c->pc + 1].v) == 1) ? tmp + 1 : tmp;
	tmp = (get_00(p->mp[c->pc + 1].v) == 2) ? tmp + 4 : tmp;
	tmp = (get_01(p->mp[c->pc + 1].v) == 2) ? tmp + 4 : tmp;
	tmp = (get_00(p->mp[c->pc + 1].v) == 3) ? tmp + 2 : tmp;
	tmp = (get_01(p->mp[c->pc + 1].v) == 3) ? tmp + 2 : tmp;
	c->pc = c->pc + 3 + tmp;
}