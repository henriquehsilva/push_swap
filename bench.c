/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:14:11 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/02 12:14:26 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops_a(t_stats *st)
{
	put_str("  sa: ");
	put_int(st->sa);
	put_str("\n  sb: ");
	put_int(st->sb);
	put_str("\n  ss: ");
	put_int(st->ss);
	put_str("\n  pa: ");
	put_int(st->pa);
	put_str("\n  pb: ");
	put_int(st->pb);
	put_str("\n");
}

static void	print_ops_b(t_stats *st)
{
	put_str("  ra: ");
	put_int(st->ra);
	put_str("\n  rb: ");
	put_int(st->rb);
	put_str("\n  rr: ");
	put_int(st->rr);
	put_str("\n  rra: ");
	put_int(st->rra);
	put_str("\n  rrb: ");
	put_int(st->rrb);
	put_str("\n  rrr: ");
	put_int(st->rrr);
	put_str("\n");
}

void	stats_print(const t_opts *opts, double disorder)
{
	t_stats	*st;

	st = get_stats();
	put_str("=== push_swap benchmark ===\n");
	put_str("Disorder: ");
	put_percent(disorder);
	put_str("Strategy: ");
	put_str(opts->strategy->name);
	put_str(" (");
	put_str(opts->strategy->complexity);
	put_str(")\n");
	put_str("Total operations: ");
	put_int(st->total);
	put_str("\n");
	print_ops_a(st);
	print_ops_b(st);
}
