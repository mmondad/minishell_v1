/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:57:53 by mmondad           #+#    #+#             */
/*   Updated: 2024/06/03 15:14:05 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*cpy_env(char **env)
{
	int i;
	int j;
	t_env	*node;
	t_env	*head;

	i = 0;
	head = NULL;
	while (env[i])
	{
		j = 0;
		node = new_node_e();
		node->line = malloc(ft_strlen(env[i]) + 1);
		while (env[i][j])
		{
			node->line[j] = env[i][j];
			j++;
		}
		node->line[j] = '\0';
		add_back_e(&head, node);
		i++;
	}
	return (head);
}

void init_info(int ac, char **av, char **env, t_info *info)
{
	info->argc = ac;
	info->argv = av;
	info->penv = env;
	info->count = 0;
	info->quotes = 0;
	info->head_e = cpy_env(env);
	info->plist = NULL;
}


int main(int argc, char **argv, char **penv)
{
	t_info	info;

	while (1)
	{
		init_info(argc, argv, penv, &info);
		info.line = readline ("minishell-0.0$ ");
		if (info.line)
			add_history(info.line);
		info.line = expand(&info);
		info.tmp_line = info.line;
		info.list = NULL;
		ft_split(&info);
		if (!stx_errors(info))
		{
			create_plist(&info);
			print_list2(info);
		}
		else
			printf("stx_error\n");
		free_list(&info);
	}
}
