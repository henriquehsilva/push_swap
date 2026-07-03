/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:14:11 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/03 09:12:40 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops_a(t_stats *st)
{
	put_str("[bench] ");
	put_str("sa: ");
	put_int(st->sa);
	put_str("  sb: ");
	put_int(st->sb);
	put_str("  ss: ");
	put_int(st->ss);
	put_str("  pa: ");
	put_int(st->pa);
	put_str("  pb: ");
	put_int(st->pb);
	put_str("\n");
}

static void	print_ops_b(t_stats *st)
{
	put_str("[bench] ");
	put_str("ra: ");
	put_int(st->ra);
	put_str("  rb: ");
	put_int(st->rb);
	put_str("  rr: ");
	put_int(st->rr);
	put_str("  rra: ");
	put_int(st->rra);
	put_str("  rrb: ");
	put_int(st->rrb);
	put_str("  rrr: ");
	put_int(st->rrr);
	put_str("\n");
}

void	stats_print(const t_opts *opts, double disorder)
{
	t_stats	*st;

	st = get_stats();
	put_str("[bench] disorder: ");
	put_percent(disorder);
	put_str("[bench] strategy: ");
	put_str(opts->strategy->name);
	put_str(" / ");
	put_str(opts->strategy->complexity);
	put_str("\n");
	put_str("[bench] total_ops: ");
	put_int(st->total);
	put_str("\n");
	print_ops_a(st);
	print_ops_b(st);
}
