/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:27:16 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/18 10:28:01 by hhonorio         ###   ########.fr       */
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

/* *************************************** */
/* Functions                               */
/* *************************************** */

int		parse_args(int argc, char **argv, t_opts *opts, t_stack *a);
int		parse_flags(int argc, char **argv, t_opts *opts, int *operands);
int		fill_stack(int argc, char **argv, int start, t_stack *a);

void	stack_init(t_stack *s);
int		stack_append(t_stack *s, int value);
void	stack_clear(t_stack *s);

void	sort_simple(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);
void	sort_adaptive(t_stack *a, t_stack *b);
#endif
