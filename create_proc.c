/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:10:14 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/06 23:21:13 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	create_proc(t_env *p)
{
	int		j;
	t_proc	*ptr;

	j = MAX_PLAYERS - 1;
	while (j >= 0)
	{
		ptr = pushproc(&p->begin, p->play[j]->adr);
		ptr->reg[0] = p->play[j]->adr;
		p->mp[ptr->reg[0]].players = 5;
		j--;
	}
}