/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:27:16 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/17 10:21:06 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* *************************************** */
/* External Libraries                      */
/* *************************************** */

# include "libft/libft.h"
# include <stdarg.h>

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

/* *************************************** */
/* functions                               */
/* *************************************** */

void	sort_simple(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);
void	sort_adaptive(t_stack *a, t_stack *b);

#endif
