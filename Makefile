# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 16:02:56 by hhonorio          #+#    #+#              #
#    Updated: 2026/07/11 11:38:17 by marbelas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

LIBFT_DIR		= ./libft
FT_PRINTF_DIR	= ./ft_printf
LIBFT			= $(LIBFT_DIR)/libft.a
FT_PRINTF		= $(FT_PRINTF_DIR)/ft_printf.a

INCLUDES		= -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

SRC				= main.c \
				  parse_args.c \
				  parse_flags.c \
			      fill_stack.c \
			      stack.c \
				  swap.c \
				  push.c \
				  rotate.c \
				  reverse_rotate.c \
				  is_sorted.c \
				  sort_simple.c \
				  strategies.c \
				  bench.c \
				  bench_utils.c \
				  stats.c \
				  compute_disorder.c \
				  sort_complex_ops.c \
				  sort_complex_base.c \
				  sort_complex.c \
				  sort_adaptive.c 
OBJ				= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re
