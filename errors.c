/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:45:31 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/23 09:45:17 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_list(t_info info)
{
	while (info.list)
	{
		printf("[%s] -> type = %d\n", info.list->txt ,info.list->type);
		info.list = info.list->next;
	}
}

void ft_putstr(char *str, int fd)
{
	int i;

	i = -1;
	while (str[++i])
		write(fd, str + i, 1);
}

void print_error(char *msg, int ext, int fd)
{
	ft_putstr(msg, fd);
	exit(ext);
}