/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:41:14 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/25 19:34:38 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(t_list **a, t_list **b)
{
	int	*chunks;

	chunks = ft_chunk_generator(*a);
	chunks_to_b(a, b, chunks);
	chunks_to_a(a, b);
	free(chunks);
}

void	determine_algo(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		swp(*a, "sa");
	else if (ft_lstsize(*a) == 3)
		three_args(a, b);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else
		sort_all(a, b);
}

void	sort_four(t_list **a, t_list **b)
{
	int	min;

	min = ft_min_max(*a, 'm');
	while (ft_atoi((*a)->content) != min)
		rotate(*a, "ra");
	*a = push(a, b, 'b');
	three_args(a, b);
	*b = push(a, b, 'a');
}

void	sort_five(t_list **a, t_list **b)
{
	int	min;

	min = ft_min_max(*a, 'm');
	if (ft_atoi(ft_lstlast(*a)->content) == min)
		rev_rot(*a, "rra");
	else
	{
		while (ft_atoi((*a)->content) != min)
			rotate(*a, "ra");
	}
	*a = push(a, b, 'b');
	min = ft_min_max(*a, 'm');
	while (ft_atoi((*a)->content) != min)
		rotate(*a, "ra");
	*a = push(a, b, 'b');
	three_args(a, b);
	*b = push(a, b, 'a');
	*b = push(a, b, 'a');
}
