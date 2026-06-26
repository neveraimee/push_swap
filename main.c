/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:46:13 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/26 19:18:40 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_opts	opts;
	t_bench	*bench;
	double	disorder;

	bench = malloc(sizeof(t_bench));
	if (!bench)
		return (1);
	ft_memset(bench, 0, sizeof(t_bench));
	a = parse_args(ac, av, bench);
	if (!a)
	{
		free(bench);
		return (0);
	}
	disorder = compute_disorder(a);
	opts.strategy = ADAPTIVE;
	opts.bench = 0;
	parse_flags(ac, av, &opts, a, bench);
	if (opts.bench == 0)
	{
		free(bench);
		bench = NULL;
	}
	if (opts.strategy == ADAPTIVE)
		adaptive_sort(a, bench);
	if (opts.strategy == SIMPLE)
		bubble_sort(a, bench);
	if (opts.strategy == MEDIUM)
		chunk_sort(a, bench);
	if (opts.strategy == COMPLEX)
		radix_sort(a, bench);
	if (opts.bench == 1)
		write_bench(bench, disorder, &opts);
	stack_free(a);
	free(bench);
	return (0);
}
