/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:25:57 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/25 19:03:25 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define REVROT 0 
#define ROT 1 

int	element_in_range(char *elem, int *chunks, int i)
{
	int	num;

	num = ft_atoi(elem);
	return ((num >= chunks[i] && num < chunks[i + 1]));
}

int	chunks_left(t_list *a, int *chunks, int i)
{
	t_list	*curr;

	curr = a;
	while (curr)
	{
		if (element_in_range(curr->content, chunks, i))
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	get_max(t_list *head)
{
	t_list	*curr;
	int		max_num;
	int		max;
	int		curr_pos;

	curr = head;
	curr_pos = 0;
	max = 0;
	max_num = ft_atoi(curr->content);
	while (curr)
	{
		if (max_num < ft_atoi(curr->content))
		{
			max = curr_pos;
			max_num = ft_atoi(curr->content);
		}
		curr = curr->next;
		curr_pos++;
	}
	return (max);
}

int	chunks_to_b(t_list **a, t_list **b, int *chunks)
{
	int	i;

	i = 0;
	while (*a)
	{
		if (ft_lstsize(*a) >= 3 && ft_lstsize(*a) <= 5)
		{
			if (ft_lstsize(*a) == 3)
				three_args(a, b);
			if (ft_lstsize(*a) == 4)
				sort_four(a, b);
			if (ft_lstsize(*a) == 5)
				sort_five(a, b);
			return 1;
		}
		while (chunks_left(*a, chunks, i))
		{
			if (element_in_range((*a)->content, chunks, i))
				*a = push(a, b, 'b');
			else
				rotate(*a, "ra");
		}
		i++;
	}
	return (i);
}

void	chunks_to_a(t_list **a, t_list **b)
{
	int	max_pos;
	int	top;
	int	bottom;

	while (*b)
	{
		while (get_max(*b))
		{
			max_pos = get_max(*b);
			top = max_pos;
			bottom = ft_lstsize(*b) - max_pos;
			determine_rotate(&top, &bottom, b);
		}
		*b = push(a, b, 'a');
	}
}
