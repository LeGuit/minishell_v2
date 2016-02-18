# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:51:30 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/15 17:54:08 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# For mem : @ before a commande hide the echo of the command

CC =	gcc
FLAGS =	-Wall -Werror -Wextra
NAME =	libftprintf.a
HEAD =	-I includes/
TEST = ft_printf


SRCS =	ft_atoi.c \
		ft_atoll.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_memrcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strrcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strlen_ch.c \
		ft_lstfind.c \
		ft_putnstr.c \
		ft_putnstr_fd.c \
		ft_ulltstr_base.c \
		ft_slltstr.c \
		ft_widetoa.c \
		ft_printf.c \
		get_mod.c \
		ft_vprintf.c \
		conversion.c \
		print_arg.c \
		process_mod.c \
		print_u.c \
		print_sign.c \
		print_str.c \
		print_c.c \
		print_wstr.c \
		display_ui.c \
		ft_printf_prefix.c \
		ft_wstrlen.c \
		ft_dlstcreate.c \
		ft_dlstdel.c \
		ft_dlstmove.c \
		ft_dlsttest.c \
		ft_dlstsort.c \
		ft_vect.c \
		ft_size_nb.c \
		get_next_line.c \
		ft_tabdel.c \
		ft_tabdup.c \
		ft_tabsize.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

test: $(TEST)

$(TEST): $(NAME) 
	$(CC) -o $@ main_test.c $^

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	@$(CC) $(FLAGS) $(HEAD) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

retest:fclean test
