/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:59:32 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/23 10:01:52 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_info	*info)
{
	t_list *tmp;

	while (info->list)
	{
		tmp = info->list;
		free(tmp->txt);
		info->list = info->list->next;
		free(tmp);
	}
	free(info->tmp_line);
}