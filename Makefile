# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 16:02:56 by hhonorio          #+#    #+#              #
#    Updated: 2026/06/18 12:21:59 by hhonorio         ###   ########.fr        #
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
			      stack.c
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
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
