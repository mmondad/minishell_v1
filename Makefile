# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:56:53 by mmondad           #+#    #+#              #
#    Updated: 2024/05/25 10:17:59 by mmondad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRS = ft_split.c linked_list.c parsing.c free_memory.c print.c utils.c syntax_errors.c validators.c length.c
OBJCTS = $(SRS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = minishell

all : $(NAME)

$(NAME) : $(OBJCTS)
	$(CC) $(CFLAGS) $(OBJCTS) -o $(NAME) -lreadline
clean :
	rm -rf $(OBJCTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
