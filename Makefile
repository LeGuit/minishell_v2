# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 10:57:07 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/11 14:56:25 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C =	clang
FLAGS =	-Wall -Wextra
NAME =	minishell
LIB =	libft/libftprintf.a
HEAD =	ft_ls.h

SRCS =	sh_loop.c \
		sh_error.c \
		sh_clear.c \
		sh_path.c \
		sh_exec.c \
		sh_builtin.c \
		sh_builtin_tools.c \
		sh_tools.c \
		sh_env.c \
		main.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C libft/ fclean
	make -C libft/

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	make -C libft/ clean
	@/bin/rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
