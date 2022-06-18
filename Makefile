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

HEADERS_DIR = ./

LIB_DIR = libft/

LIB = libft.a

NAME = pipex

OBJS = $(SRCS:.c=.o)

all:		$(NAME)


$(NAME):	$(OBJS)
				make -C $(LIB_DIR)
				$(CC) $(CFLAGS) -I$(HEADERS_DIR) -o $(NAME) $(OBJS) $(LIB_DIR)$(LIB)

clean:
				make -C $(LIB_DIR) clean
				rm -f $(OBJS)

fclean:		clean
				make -C $(LIB_DIR) fclean
				rm -rf $(NAME)				

re:			fclean all

.PHONY: all clean fclean re
