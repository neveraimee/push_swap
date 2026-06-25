/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 18:41:30 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 16:28:29 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_max_position(t_stack *b)
{
    t_node  *tmp;
    int     max;
    int     pos;
    int     max_pos;

    tmp = b->top;
    max = tmp->index;
    pos = 0;
    max_pos = 0;
    while (tmp)
    {
        if (tmp->index > max)
        {
            max = tmp->index;
            max_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return (max_pos);
}

static int find_max_index(t_stack *b)
{
    t_node  *tmp;
    int     max;

    tmp = b->top;
    max = tmp->index;
    while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }
    return (max);
}

static void push_chunks(t_stack *a, t_stack *b, t_bench *bench)
{
    int chunk_size;
    int chunk_min;
    int chunk_max;
    int i;
    int orignal_size;

    chunk_size = ft_sqrt(a->size); //how big each chunk is, cast to int so not decimal by default
    chunk_min = 0; //start of current chunk
    chunk_max = chunk_size; //end of current chunk
    while (stack_size(a)) //while a is not empty
    {
        orignal_size = a->size;
        i = 0;
        while (i < orignal_size) // while index is less than stack size
        {
            if (a->top->index >= chunk_min && a->top->index < chunk_max) 
                op_pb(a, b, bench); //chunk 1 push to b
            else
                op_ra(a, bench); //rotate to the bottom too big for now
            i++;
        }
        chunk_min += chunk_size; //go to next chunk once complete
        chunk_max += chunk_size; 
    }
}

static void pull_chunks(t_stack *a, t_stack *b, t_bench *bench)
{
    int max;
	int position;

    while (stack_size(b)) //while b has content
    {
        max = find_max_index(b); // max = biggest index
		position = find_max_position(b); // position in b 
        if (position <= b->size / 2) // if position is less than half of stack size 
        {
            while (b->top->index != max)  // keep rotating until max is on top
                op_rb(b, bench); // shift up all elements of stack b by one
        }
        else
        {
            while (b->top->index != max)  // keep rotating until max is on top
                op_rrb(b, bench); // shift down all elements of stack b by one
        }
        op_pa(a, b, bench);
    }
}

void    chunk_sort(t_stack *a, t_bench *bench)
{
	t_stack *b;

	b = stack_new(); //create stack b
	push_chunks(a, b, bench); // push chunk to b
	pull_chunks(a, b, bench); //pull back to a in the correct order
	stack_free(b); //free b
}
