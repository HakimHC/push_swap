/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:08:51 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/29 01:56:54 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_list *head)
{
	t_list	*curr;

	curr = head;
	while (curr->next)
	{
		if (ft_atoi(curr->content) > ft_atoi(curr->next->content))
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	first_case(t_list **a, t_list **b)
{
	swp(*a, "sa");
	if (!is_ordered(*a))
	{
		*a = push(a, b, 'b');
		swp(*a, "sa");
		*b = push(a, b, 'a');
	}
}

void	second_case(t_list **a, t_list **b)
{
	*a = push(a, b, 'b');
	swp(*a, "sa");
	*b = push(a, b, 'a');
	if (!is_ordered(*a))
		swp(*a, "sa");
}

void	three_args(t_list **a, t_list **b)
{
	char	*first;
	char	*second;
	char	*third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (is_ordered(*a))
		return ;
	if ((ft_atol(first) > ft_atol(second))
		&& (ft_atol(second) < ft_atol(third)))
	{
		first_case(a, b);
		return ;
	}
	if (ft_atol(first) < ft_atol(second) && ft_atol(second) > ft_atol(third))
	{
		second_case(a, b);
		return ;
	}
	rotate(*a, "ra");
	swp(*a, "sa");
}
