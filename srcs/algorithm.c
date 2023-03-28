/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:08:51 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/28 22:55:02 by hakahmed         ###   ########.fr       */
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

void	three_args(t_list **a, t_list **b)
{
	if (is_ordered(*a))
		return ;
	if ((ft_atol((*a)->content) > ft_atol((*a)->next->content))
		&& (ft_atol((*a)->next->content) < ft_atol((*a)->next->next->content)))
	{
		swp(*a, "sa");
		(void) b;
		return ;
	}

}
