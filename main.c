/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zumralkan <zumralkan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:13:44 by makbas            #+#    #+#             */
/*   Updated: 2023/10/04 22:55:11 by zumralkan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char **argv)
{
	int		i;
	long	nb;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		if (!is_num(args[i]))
			error();
		if (is_duplicate(nb, args, i))
			error();
		if (nb < -2147483648 || nb > 2147483647)
			error();
		i++;
	}
}

void	fill_stack_value(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	indexing(*stack);
}

void	indexing(t_list *stack)
{
	t_list	*new;
	t_list	*max;
	int		value;
	int		count;

	count = ft_lstsize(stack);
	while (count > 0)
	{
		new = stack;
		value = -2147483648;
		max = NULL;
		while (new)
		{
			if (new->value > value && new->index == -1)
			{
				value = new->value;
				max = new;
			}
			else
				new = new->next;
		}
		if (max != NULL)
			max->index = count;
		count--;
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack_value(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
