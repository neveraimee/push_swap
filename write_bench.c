/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:16:22 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 20:46:26 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_each_op(char *operation, int count) //for norm compilance 
{
	ft_putstr_fd(operation, 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

static void	write_ops(t_bench *bench)
{
	write_each_op("sa:  ", bench->sa);
	write_each_op("sb:  ", bench->sb);
	write_each_op("ss:  ", bench->ss);
	write_each_op("pa:  ", bench->pa);
	write_each_op("pb:  ", bench->pb);
	write_each_op("ra:  ", bench->ra);
	write_each_op("rb:  ", bench->rb);
	write_each_op("rr:  ", bench->rr);
	write_each_op("rra: ", bench->rra);
	write_each_op("rrb: ", bench->rrb);
	write_each_op("rrr: ", bench->rrr);
}

static void	write_disorder(double disorder)
{
	int	whole;
	int	decimal;

	whole = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	ft_putstr_fd("disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putnbr_fd(0, 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	write_strategy(t_opts *opts)
{
	ft_putstr_fd("strategy: ", 2);
	if (opts->strategy == ADAPTIVE)
		ft_putstr_fd("ADAPTIVE\n", 2);
	else if (opts->strategy == SIMPLE)
		ft_putstr_fd("SIMPLE\n", 2);
	else if (opts->strategy == MEDIUM)
		ft_putstr_fd("MEDIUM\n", 2);
	else if (opts->strategy == COMPLEX)
		ft_putstr_fd("COMPLEX\n", 2);
}

void	write_bench(t_bench *bench, double disorder, t_opts *opts)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss
		+ bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr;
	write_disorder(disorder);
	write_strategy(opts);
	ft_putstr_fd("total operations: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
	write_ops(bench);
}
