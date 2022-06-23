# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 16:47:46 by bgenie            #+#    #+#              #
#    Updated: 2022/06/18 19:40:00 by bgenie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	pipex.c \
		exec.c \
		pipex_utils.c \
		ft_split.c

HEADERS_DIR = ./

NAME = pipex

OBJS = $(SRCS:.c=.o)

LEAKS_S = leaks.c

LEAKS_O = $(LEAKS_S:.c=.o)

all:		$(NAME)


$(NAME):	$(OBJS)
				@printf "\e[33mcompiling %s...\e[0m\n" $(NAME)
				@$(CC) $(CFLAGS) -I$(HEADERS_DIR) -o $(NAME) $(OBJS)

leaks:		$(OBJS) $(LEAKS_O)
				@printf "\e[33mcompiling %s with leaks check...\e[0m\n" $(NAME)
				@$(CC) $(CFLAGS) -I$(HEADERS_DIR) -o $(NAME) $(OBJS) $(LEAKS_O)

clean:
				@printf "\e[33mcleaning object files...\e[0m\n"
				@rm -f $(OBJS)

fclean:		clean
				@printf "\e[33mcleaning binary files...\e[0m\n"
				@rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
