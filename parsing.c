/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:57:53 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/27 20:25:08 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	t_info	info;

	while (1)
	{
		info.line = readline ("minishell-0.0$ ");
		if (info.line)
			add_history(info.line);
		info.tmp_line = info.line;
		info.list = NULL;
		ft_split(&info);
		if (!stx_errors(info))
		{
			//print_list(info);
			create_plist(&info);
			print_list2(info);
		}
		else
			printf("stx_error\n");
		free_list(&info);
	}
}
