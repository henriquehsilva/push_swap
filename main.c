/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 09:00:19 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/02 07:57:37 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(t_stack *a, t_stack *b);

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
	if (!opts.strategy)
		error_exit(&a, &b);
	opts.strategy->sort(&a, &b);
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
