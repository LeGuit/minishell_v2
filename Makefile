# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 10:57:07 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/16 16:57:27 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C =	clang
FLAGS =	-Wall -Werror -Wextra
NAME =	minishell
LIB =	libft/libftprintf.a
HEAD =	ft_ls.h

SRCS =	sh_loop.c \
		sh_error.c \
		sh_error_status.c \
		sh_path.c \
		sh_exec.c \
		builtin_cd.c \
		builtin_echo.c \
		builtin_env.c \
		builtin_exit.c \
		builtin_help.c \
		builtin_printenv.c \
		builtin_pwd.c \
		builtin_setenv.c \
		builtin_unsetenv.c \
		builtin_export.c \
		sh_builtin_tools.c \
		sh_sig_binding.c \
		sh_tools.c \
		sh_env.c \
		sh_env_tools.c \
		ft_access.c \
		sh_path_tools.c \
		option.c \
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
