/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:25:57 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/31 16:53:20 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define REVROT 0 
#define ROT 1 

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


t_list	*ft_lstmid(t_list *head)
{
	int	mid;
	t_list	*curr;

	mid = ft_lstsize(head) / 2;
	curr = head;
	while (ft_lstsize(curr) != mid)
		curr = curr->next;
	return (curr);
}

int ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int	chunk_element_calculator(t_list **a, int *chunks, int i)
{
	int	mid;
	int	bottom;
	int	top;
	int     pos;
	t_list	*curr;

	mid = ft_lstsize(*a) / 2;
	curr = *a;
	top = 0;
	pos = 0;
	while (ft_lstsize(curr) != mid && !top)
	{
		if (element_in_range(curr->content, chunks, i))
		{
			top = pos;
			break;
		}
		pos++;
		curr = curr->next;
	}
	curr = ft_lstmid(*a);
	bottom = 0;
	pos = mid;
	while (curr)
	{
		if (element_in_range(curr->content, chunks, i))
		{
			bottom = pos;
		}
		pos++;
		curr = curr->next;
	}
	// ft_printf("BOTTOM %d\n", bottom);
	bottom = ft_lstsize(*a) - bottom;
	// ft_printf("BOTTOM %d - TOP %d\n", bottom, top);
	return (ft_abs(bottom) > top);
}

void rotator(t_list **a, int *chunks, int i)
{
	int	rot;
	t_list *curr;

	rot = chunk_element_calculator(a, chunks, i);
	curr = *a;
	if (rot)
	{
		while (!element_in_range(curr->content, chunks, i))
			rotate(*a, "ra");
	}
	else 
	{
		while (!element_in_range(curr->content, chunks, i))
			rev_rot(*a, "rra");
	}
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

int	chunks_to_b(t_list **a, t_list **b, int *chunks)
{
	int	i;

	i = 0;
	while (*a)
	{
		while (chunks_left(*a, chunks, i))
		{
			if (element_in_range((*a)->content, chunks, i))
				*a = push(a, b, 'b');
			else
				rotator(a, chunks, i);
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
