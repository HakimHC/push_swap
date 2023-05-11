/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:26:07 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/25 19:20:47 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_max(t_list *head, char m)
{
	int		minmax;
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
	int	mean;
	int	i;
	int	len;

	if (ft_lstsize(head) <= 10)
		len = 3;
	else if (ft_lstsize(head) <= 100)
		len = 7;
	else
		len = 10;
	min = ft_min_max(head, 'm');
	mean = (ft_min_max(head, 'M') - min) / len;
	chunks = (int *) malloc(len * sizeof(int));
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < len)
	{
		chunks[i] = min + (i * mean);
		i++;
	}
	chunks[i] = ft_min_max(head, 'M') + 1;
	return (chunks);
}

void	determine_rotate(int *top, int *bottom, t_list **b)
{
	if (*top <= *bottom)
	{
		rotate(*b, "rb");
		(*top)--;
		(*bottom)++;
	}
	else
	{
		rev_rot(*b, "rrb");
		(*top)++;
		(*bottom)--;
	}
}

void	ft_nothing(void *a)
{
	(void) a;
}

/* int	main(int argc, char *argv[]) */
/* { */
/* 	t_list	*head; */

/* 	head = args_to_list(argv + 1, 0); */
/* 	// ft_printf("MIN - %d\n", ft_min_max(head, 'm')); */
/* 	// ft_printf("MAX - %d\n", ft_min_max(head, 'M')); */
/* 	int i = 0; */
/* 	int *chunks = ft_chunk_generator(head); */
/* 	while (i < 5) */
/* 	{ */
/* 		ft_printf("%d ", chunks[i]); */
/* 		i++; */
/* 	} */
/* 	return (0); */
/* } */
