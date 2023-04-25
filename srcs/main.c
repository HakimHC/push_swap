/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:35:24 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/25 17:58:13 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	leaks(void)
{
	system("leaks -q push_swap");
}

char	**process_args(int argc, char **argv)
{
	char	**split;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	return (split);
}

void	err_han(t_list *a)
{
	if (ft_lstsize(a) == 1)
	{
		ft_error_handler(a);
		exit(EXIT_SUCCESS);
	}
	ft_error_handler(a);
	if (is_ordered(a))
		exit(EXIT_SUCCESS);
}

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
	/* ft_printf("%d\n", ft_lstsize(*a)); */
	/* if (ft_lstsize(*a) == 2) */
	/* 	swp(*a, "sa"); */
	if (ft_lstsize(*a) == 3)
		three_args(a, b);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else
		sort_all(a, b);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int	b_free;
	char	**split;

	/* atexit(leaks); */

	b_free = 0;
	if (argc == 2)
		b_free = 1;
	split = process_args(argc, argv);
	a = args_to_list(split, 0);
	b = NULL;
	err_han(a);
	determine_algo(&a, &b);
	/* printf_list(a); */
	if (b_free)
		ft_free_strarr(split);
	ft_lstclear(&a, &ft_nothing);
	ft_lstclear(&b, &ft_nothing);
}
