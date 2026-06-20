/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 09:00:19 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/20 08:38:51 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(t_stack *a, t_stack *b);
static void	print_stack(t_stack *s);

int	main(int argc, char **argv)
{
	t_opts	opts;
	t_stack	a;
	t_stack	b;

	ft_bzero(&opts, sizeof(opts));
	stack_init(&a);
	stack_init(&b);
	if (parse_args(argc, argv, &opts, &a) != 0)
		error_exit(&a, &b);
	print_stack(&a);
	ft_printf("Teste\n");
	ft_printf("%i\n", is_sorted(&a));
	print_stack(&a);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

static void	error_exit(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	stack_clear(a);
	stack_clear(b);
	exit(1);
}

static void	print_stack(t_stack *s)
{
	t_node	*node;

	node = s->top;
	while (node)
	{
		ft_printf("%d\n", node->value);
		node = node->next;
	}
}
