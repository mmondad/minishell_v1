/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:57:53 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/23 10:51:34 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_quotes(char *line)
{
	char	tmp;
	int		i;
	int		flag;

	tmp = 0;
	i = -1;
	flag = 0;
	while (line[++i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && !flag)
		{
			tmp = line[i++];
			flag = 1;
		}
		if (line[i] && line[i] == tmp && flag)
			flag = 0;
	}
	return (flag);
}
int check_token(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	check_sep(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int main(void)
{
	t_info	info;

	while (1)
	{
		info.line = readline ("minishell-0.0$ ");
		if (info.line)
			add_history(info.line);
		info.tmp_line = info.line;
		while (*info.line && *info.line == ' ')
			info.line++;
		if (!check_quotes(info.tmp_line))
		{
			ft_split(&info);
			print_list(info);
		}
		else
			printf("stx_error\n");
		free_list(&info);
	}
}
