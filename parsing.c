/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:57:53 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/25 16:02:17 by mmondad          ###   ########.fr       */
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
		while (*info.line && check_escape(*info.line))
			info.line++;
		ft_split(&info);
		
		create_plist(&info);
		if (!stx_errors(info))
		{
			//print_list(info);
		}
		else
			printf("stx_error\n");
		free_list(&info);
	}
}
