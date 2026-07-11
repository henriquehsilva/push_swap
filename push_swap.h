/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:27:16 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/11 11:23:02 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* *************************************** */
/* External Libraries                      */
/* *************************************** */

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

/* *************************************** */
/* Structs                                 */
/* *************************************** */

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_strategy
{
	const char	*flag;
	const char	*name;
	const char	*complexity;
	void		(*sort)(t_stack *a, t_stack *b);
}	t_strategy;

typedef struct s_opts
{
	const t_strategy	*strategy;
	unsigned int		seed;
	int					bench;
	int					size;
	int					runs;
}	t_opts;

typedef struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_stats;

# define QS_A		1
# define QS_DESC	2

# define DISORDER_LOW 0.2
# define DISORDER_MED 0.5 

/* *************************************** */
/* Functions                               */
/* *************************************** */

int					parse_args(int argc, char **argv, t_opts *opts, t_stack *a);
int					parse_flags(int argc, char **argv, \
									t_opts *opts, int *operands);
int					fill_stack(int argc, char **argv, int start, t_stack *a);

void				stack_init(t_stack *s);
int					stack_append(t_stack *s, int value);
void				stack_clear(t_stack *s);

void				sort_simple(t_stack *a, t_stack *b);
void				sort_medium(t_stack *a, t_stack *b);
void				sort_complex(t_stack *a, t_stack *b);
void				sort_adaptive(t_stack *a, t_stack *b);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

int					is_sorted(t_stack *s);

const t_strategy	*find_strategy(const char *flag);
const t_strategy	*get_default_strategy(void);

t_stats				*get_stats(void);
void				stats_reset(void);
void				stats_print(const t_opts *opts, double disorder);
void				put_str(const char *s);
void				put_int(int n);
void				put_percent(double ratio);
double				compute_disorder(t_stack *a);

void				op_swap(t_stack *active, int is_a);
void				op_rotate(t_stack *active, int is_a);
void				op_reverse_rotate(t_stack *active, int is_a);
void				op_push(t_stack *active, t_stack *aux, int is_a);
void				op_push_back(t_stack *active, t_stack *aux, int is_a);

int					partition(t_stack *active, t_stack *aux, \
								int size, int mode);
void				sort_two(t_stack *active, int mode);
void				sort_three_generic(t_stack *active, int mode);
#endif
