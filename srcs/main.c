/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:35:24 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/31 02:16:31 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	**split;

	b = 0;
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	a = args_to_list(split, 0);
	// if (ft_lstsize(a) == 3)
	// {
	// 	three_args(&a, &b);
	// 	return (0);
	// }
	// if (!a)
	// 	return (0);
	ft_error_handler(a);
	// if (is_ordered(a))
	// 	return (0);
	// (void) b;
	// int chunks[] = {1, 101, 151, 201, 251, 301, 351, 401, 451, 501};
	int chunks[] = {1, 12, 23, 34, 45, 56, 67, 78, 89, 101};
	// int chunks[] = {1, 30, 60, 80, 101};
	chunks_to_b(&a, &b, chunks);
	// printf_list(b);
	chunks_to_a(&a, &b);
	// printf_list(b);
	// if (is_ordered(a))
	// 	ft_printf("ORDERED\n");
	// printf_list(a);
	// printf_list(b);
	// ft_lstclear(&a, &ft_nothing);
	// free(split);
	// ft_lstclear(&b, &ft_nothing);
	// system("leaks -q push_swap");
}
