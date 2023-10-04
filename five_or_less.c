/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zumralkan <zumralkan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:13:28 by makbas            #+#    #+#             */
/*   Updated: 2023/10/04 18:12:00 by zumralkan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap(stack_a, 'a');
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b, 1);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

void	sort_2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, 'a');
}

void	sort_3(t_list **stack_a)
{
	sort_2(stack_a);
	if ((*stack_a)->value > ((*stack_a)->next->next->value))
		reverse_rotate(stack_a, 'a');
	sort_2(stack_a);
	if ((*stack_a)->next->value > ((*stack_a)->next->next->value))
	{
		reverse_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b, int min)
{
	int		min_order;
	t_list	*head;

	min_order = 0;
	head = *stack_a;
	while (head)
	{
		if (head->index == min)
			break ;
		min_order++;
		head = head->next;
	}
	if (min_order == 1)
		rotate(stack_a, 'a');
	else if (min_order == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (min_order == 3)
		reverse_rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int		min_value;

	min_value = min_order(stack_a);
	if (min_value == 1)
		rotate(stack_a, 'a');
	else if (min_value == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (min_value == 3)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (min_value == 4)
		reverse_rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b, 2);
	push(stack_b, stack_a, 'a');
}
