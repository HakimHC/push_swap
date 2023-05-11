/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:35:24 by hakahmed          #+#    #+#             */
/*   Updated: 2023/05/04 12:02:23 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		b_free;
	char	**split;

	b_free = 0;
	if (argc == 2)
		b_free = 1;
	split = process_args(argc, argv);
	a = args_to_list(split, 0);
	b = NULL;
	err_han(a);
	determine_algo(&a, &b);
	if (b_free)
		ft_free_strarr(split);
	ft_lstclear(&a, &ft_nothing);
	ft_lstclear(&b, &ft_nothing);
}
