/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:25:57 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/31 01:26:27 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	element_in_range(char *elem, int *chunks, int i)
{
	int	num;

	// int chunks[] = {1, 20, 60, 80, 101};

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

int	chunks_to_b(t_list **a, t_list **b, int *chunks)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		while (chunks_left(*a, chunks, i))
		{
			if (element_in_range((*a)->content, chunks, i))
			{
				*a = push(a, b, 'b');
				// ft_printf("%s\n", (*b)->content);
			}
			else
				rotate(*a, "ra");
		}
		// ft_printf("-----------\n");
		i++;
	}
	return (i);
}

int	get_max(t_list *head)
{
	t_list	*curr;
	int	max_num;
	int	max;
	int	curr_pos;

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
		if (top <= bottom)
			{
				rotate(*b, "rb");
				top--;
				bottom++;
			}
			else 
			{
				rev_rot(*b, "rrb");
				top++;
				bottom--;
			
			}
		}
		*b = push(a, b, 'a');
	}
}
