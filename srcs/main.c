/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:35:24 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/19 15:46:16 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
	ft_error_handler(a);
	if (ft_lstsize(a) == 3)
	{
		three_args(&a, &b);
		return 0;
	}
	if (ft_lstsize(a) == 3)
		three_args(&a, &b);
	int *chunks = ft_chunk_generator(a);
	chunks_to_b(&a, &b, chunks);
	chunks_to_a(&a, &b);
	ft_lstclear(&a, &ft_nothing);
	if (argc == 2)
		ft_free_strarr(split);
	ft_lstclear(&b, &ft_nothing);
	system("leaks -q push_swap");
}
