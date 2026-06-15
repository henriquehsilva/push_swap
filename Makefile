# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 16:02:56 by hhonorio          #+#    #+#              #
#    Updated: 2026/06/15 09:38:51 by hhonorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 	= push_swap.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf
LIBFT_DIR = ./libft
LIBFT   = $(LIBFT_DIR)/libft.a
SRCS    = 

OBJS    = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $@
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
