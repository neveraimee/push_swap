/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:52:21 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 21:25:10 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_bench *bench)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		bubble_sort(a, bench);
	else if (disorder < 0.5)
		chunk_sort(a, bench);
	else
		radix_sort(a, bench);
}
