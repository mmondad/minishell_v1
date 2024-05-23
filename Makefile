# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:56:53 by mmondad           #+#    #+#              #
#    Updated: 2024/05/23 10:46:15 by mmondad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRS = ft_split.c linked_list.c parsing.c free_memory.c errors.c utils.c
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
