/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:14:24 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/25 16:03:27 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	stx_errors(t_info info)
{
	t_list *list = info.list;

	if (list && list->type == PIPE)
		return (1);
	while (list)
	{
		if ((list->next && list->type != WORD && list->next->type == PIPE) || !list->type)
			return (1);
		if ((!list->next && list->type != WORD) || check_quotes(info.tmp_line))
			return (1);
		list = list->next;
	}
	return (0);
}
