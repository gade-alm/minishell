# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 10:52:52 by gabriel           #+#    #+#              #
#    Updated: 2023/01/25 18:07:51 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(SRCS_DIR)/main.c \

SRCS_DIR	= srcs

OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	= objs

NAME		= minishell

CC			= cc

CFLAGS 		= -Wall -Wextra -Werror -pthread -I includes -g -fsanitize=address

RM 			= rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all