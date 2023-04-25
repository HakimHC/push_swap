/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:41:14 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/25 17:44:48 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (ft_atoi((*a)->content) != min)
		rotate(*a, "ra");
	*a = push(a, b, 'b');
	min = ft_min_max(*a, 'm');
	while (ft_atoi((*a)->content) != min)
		rotate(*a, "ra");
	*a = push(a, b, 'b');
	three_args(a, b);
	*b = push(a, b, 'a');
	*b = push(a, b, 'a');
}
