/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:26:07 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/30 01:21:48 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_range_calculator(t_list *head)
{
	int	sum;
	t_list	*curr;

	curr = head;
	sum = 0;
	while (curr)
	{
		sum += ft_atoi(curr->content);
		curr = curr->next;
	}
	return (sum / ft_lstsize(head));
}

int	ft_min_max(t_list *head, char m)
{
	int	minmax;
	t_list	*curr;

	curr = head;
	minmax = ft_atoi(curr->content);
	while (curr)
	{
		if (m == 'M' && minmax < ft_atoi(curr->content))
			minmax = ft_atoi(curr->content);
		else if (m == 'm' && minmax > ft_atoi(curr->content))
			minmax = ft_atoi(curr->content);
		curr = curr->next;
	}
	return (minmax);
}

int	*ft_chunk_generator(t_list *head)
{
	int	*chunks;
	int	min;
	int	max;
	int	mean;
	int	i;

	min = ft_min_max(head, 'm');
	max = ft_min_max(head, 'M');
	mean = ft_range_calculator(head);
	chunks = (int *) malloc(5 * sizeof(int));
	if (!chunks)
		return (0);
	i = 0;
	while (i < 4)
	{
		chunks[i] = min + (i * mean);
		i++;
	}
	chunks[i] = max;
	return (chunks);
}

// int	main(int argc, char *argv[])
// {
// 	t_list	*head;
//
// 	head = args_to_list(argv + 1, 0);
// 	// ft_printf("MIN - %d\n", ft_min_max(head, 'm'));
// 	// ft_printf("MAX - %d\n", ft_min_max(head, 'M'));
// 	int i = 0;
// 	int *chunks = ft_chunk_generator(head);
// 	while (i < 5)
// 	{
// 		ft_printf("%d ", chunks[i]);
// 		i++;
// 	}
// 	return (0);
// }
