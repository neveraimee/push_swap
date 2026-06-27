/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:46:13 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/27 21:29:50 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_alg(t_opts opts, t_bench *bench, double disorder, t_stack *a)
{
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
}

void	assign_values(t_opts *opts, t_clean *data, t_stack *a, t_bench *bench)
{
	opts->strategy = ADAPTIVE;
	opts->bench = 0;
	data->a = a;
	data->bench = bench;
}

int	init_data(t_bench **bench, t_clean **data)
{
	*bench = malloc(sizeof(t_bench));
	if (!*bench)
		return (1);
	*data = malloc(sizeof(t_clean));
	if (!*data)
	{
		free(*bench);
		return (1);
	}
	ft_memset(*bench, 0, sizeof(t_bench));
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_opts	opts;
	t_bench	*bench;
	t_clean	*data;
	double	disorder;

	if (init_data(&bench, &data))
		return (1);
	a = parse_args(ac, av, bench);
	if (!a)
	{
		free(bench);
		free(data);
		return (0);
	}
	disorder = compute_disorder(a);
	assign_values(&opts, data, a, bench);
	parse_flags(ac, av, &opts, data);
	choose_alg(opts, bench, disorder, a);
	stack_free(a);
	free(bench);
}
