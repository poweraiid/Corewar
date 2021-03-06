/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:19:16 by Gufortel          #+#    #+#             */
/*   Updated: 2019/02/12 21:13:59 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

/*
** parse.c
*/

void	parsename(void);

/*
** op.c
*/

t_op	*buildtab(void);

/*
** env.c
*/

t_env	*createenv(void);
void	delenv(t_env **p);

/*
** play.c
*/

t_play	*createplay(char *name);
void	delplay(t_play **p);

/*
** proc.c
*/

t_proc	*createproc(void);
t_proc	*pushproc(t_proc **begin, int pc);
t_proc	*pushprocfirst(t_proc **begin, int pc);
void	delproc(t_proc **begin);
void	clean_proc(t_proc **begin);

/*
** erreur.c
*/

void	erreur(char *str);

/*
** openfile.c
*/

void	openfile(t_env *p);

/*
** loadchamp.c
*/

void	loadchamp(t_play *p);

/*
** fd.c
*/

int		fd_open(char *name, int i);
int		fd_close(int fd);

/*
** dump.c
*/

void	dump_map(t_env *p);
void	dump_map_bonus(t_env *p);

/*
** create_proc.c
*/

void	create_proc(t_env *p);

/*
** loop.c
*/

void	loop(t_env *p, int i, t_proc *ptr);

/*
** arg.c
*/

int		argint(t_env *p, int pc, int size);

/*
** live.c
*/

void	live(t_env *p, t_proc *ptr);

/*
** ld.c
*/

void	ld(t_env *p, t_proc *ptr);

/*
** get_arg.c
*/

int		get_00(int x);
int		get_01(int x);
int		get_02(int x);
int		get_03(int x);

/*
** st.c
*/

void	st(t_env *p, t_proc *c);

/*
** life.c
*/

int		life(t_env *p);
void	winchamp(t_env *p);

/*
** add.c
*/

void	add(t_env *p, t_proc *c);

/*
** sub.c
*/

void	sub(t_env *p, t_proc *c);

/*
** and.c
*/

void	and(t_env *p, t_proc *c);

/*
** or.c
*/

void	or(t_env *p, t_proc *c);

/*
** get_ind.c
*/

int		get_ind(int val, t_env *p, int pc, int bit);
int		get_ind_all(int val, t_env *p, int pc, int bit);

/*
** get_all.c
*/

int		get_all(t_env *p, int type, t_proc *c, int nbarg);
int		get_all_all(t_env *p, int type, t_proc *c, int nbarg);

/*
** xor.c
*/

void	xor(t_env *p, t_proc *c);

/*
** zjmp.c
*/

void	zjmp(t_env *p, t_proc *c);

/*
** ldi.c
*/

void	ldi(t_env *p, t_proc *c);

/*
** fork.c
*/

void	op_fork(t_env *p, t_proc *c);

/*
** sti.c
*/

void	sti(t_env *p, t_proc *c);

/*
** lld.c
*/

void	lld(t_env *p, t_proc *c);

/*
** lldi.c
*/

void	lldi(t_env *p, t_proc *c);

/*
** lfork.c
*/

void	op_lfork(t_env *p, t_proc *c);

/*
** printf_reg.c
*/

void	print_reg(t_env *p, t_proc *c, int adr, int val);

/*
** aff.c
*/

void	aff(t_env *p, t_proc *c);
void	aff2(t_env *p, t_proc *c, int j);

#endif
