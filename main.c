/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 09:00:19 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/03 06:37:08 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_opts	opts;
	t_stack	a;
	t_stack	b;
	double	disorder;

	ft_bzero(&opts, sizeof(opts));
	stack_init(&a);
	stack_init(&b);
	if (parse_args(argc, argv, &opts, &a) != 0)
		error_exit(&a, &b);
	if (!opts.strategy)
		error_exit(&a, &b);
	disorder = compute_disorder(&a);
	stats_reset();
	opts.strategy->sort(&a, &b);
	if (opts.bench)
		stats_print(&opts, disorder);
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
