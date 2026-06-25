/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:37:14 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 18:03:28 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a, t_bench *bench)
{
	t_node *first;
	t_node *second;

	if (bench)
        bench->sa++;
	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	first->next = second->next; // skip one by making first next equal seconds next
	second->next = first; // second points to first 
	a->top = second; // second becomes top
	write(1, "sa\n", 3);
}

void	op_sb(t_stack *b, t_bench *bench)
{
	t_node *first;
	t_node *second;


	if (bench)
		bench->sb++;
	if (!b || b->size < 2)
		return;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	write(1, "sb\n", 3);
}

void	op_ss(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node *first;
	t_node *second;

	if (bench)
		bench->ss++;
	if (a && a->size >= 2)
	{
		first = a->top;
		second = a->top->next;
		first->next = second->next;
		second->next = first;
		a->top = second;
	}
	if (b && b->size >= 2)
	{
		first = b->top;
		second = b->top->next;
		first->next = second->next;
		second->next = first;
		b->top = second;
	}
	write(1, "ss\n", 3);
}

void op_pa(t_stack *a, t_stack *b, t_bench *bench)
{
    int val;
    int idx;

    if (bench)
        bench->pa++;
    if (!b || stack_size(b) == 0)
        return ;
    val = stack_peek(b); // look at value before touching anything
    idx = stack_peek_index(b); // look at index before touching anything
    stack_pop(b); // now safely remove the node
    stack_push(a, val, idx);  // push both across to a
    write(1, "pa\n", 3);
}

void op_pb(t_stack *a, t_stack *b, t_bench *bench)
{
    int val;
    int idx;

    if (bench)
        bench->pb++;
    if (!a || stack_size(a) == 0)
        return ;
    val = stack_peek(a); // grab value safely
    idx = stack_peek_index(a); // grab index safely
    stack_pop(a); // remove node
    stack_push(b, val, idx);  // push both across to b
    write(1, "pb\n", 3);
}

void	op_ra(t_stack *a, t_bench *bench) //if a is empty??
{
	t_node *temp;
	t_node *index;

	if (bench)
		bench->ra++;
	if(!a || a->size < 2)
		return ;
	temp = a->top;
	index = a->top; //set both to top
	while (index->next != NULL) //while we are not at the last node
		index = index->next; //walk to the last node
	index->next = temp; // add old top to end of the list 
	a->top = temp->next; // temp->next is the second element and becomes new top 
	temp->next = NULL; // set last nodes next to null
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b, t_bench *bench)
{
	t_node *temp;
	t_node *index;

	if (bench)
		bench->rb++;
	if(!b || b->size < 2)
		return ;
	temp = b->top;
	index = b->top;
	while(index->next != NULL)
		index = index->next;
	index->next = temp;
	b->top = temp->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node *temp;
	t_node *index;

	if (bench)
		bench->rr++;
	if(a && a->size >= 2)
	{
		temp = a->top;
		index = a->top;
		while (index->next != NULL)
			index = index->next;
		index->next = temp;
		a->top = temp->next;
		temp->next = NULL;
	}
	if (b && b->size >= 2)
	{
		temp = b->top;
		index = b->top;
		while (index->next != NULL)
			index = index->next;
		index->next = temp;
		b->top = temp->next;
		temp->next = NULL;
	}
	write(1, "rr\n", 3);
}

void	op_rra(t_stack *a, t_bench *bench)
{
	t_node *current;
	t_node *prev;
	t_node *temp;

	if (bench)
		bench->rra++;
	if (!a || a->size < 2)
		return ;
	current = a->top;//
	temp = a->top;
	while (current->next != NULL)
	{
		prev = current; //second last
		current = current->next; //last
	}
	a->top = current; //top becomes last node value
	current->next = temp; //new top next is old top
	prev->next = NULL; //second last becomes last and is set to NULL
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b, t_bench *bench)
{
	t_node *current;
	t_node *prev;
	t_node *temp;

	if (bench)
		bench->rrb++;
	if (!b || b->size < 2)
		return ;
	current = b->top;
	temp = b->top;
	while (current->next != NULL)
	{
		prev = current; //second last
		current = current->next; //last
	}
	b->top = current; // last becomes top
	current->next = temp;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node *current;
	t_node *prev;
	t_node *temp;

	if (bench)
		bench->rrr++;
	if (a && a->size >= 2) 
	{
		current = a->top;
		temp = a->top;
		while(current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		a->top = current;
		current->next = temp;
		prev->next = NULL;
	}
	if (b && b->size >= 2)
	{
		current = b->top;
		temp = b->top;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		b->top = current;
		current->next = temp;
		prev->next = NULL;
	}
	write(1, "rrr\n", 4);
}
