/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 08:37:25 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/18 08:38:26 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

int	stack_append(t_stack *s, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (1);
	node->value = value;
	node->next = NULL;
	node->prev = s->bottom;
	if (s->bottom)
		s->bottom->next = node;
	else
		s->top = node;
	s->bottom = node;
	s->size++;
	return (0);
}

void	stack_clear(t_stack *s)
{
	t_node	*node;
	t_node	*next;

	node = s->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	stack_init(s);
}
