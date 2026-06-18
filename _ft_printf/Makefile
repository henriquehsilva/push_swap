# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 16:02:56 by hhonorio          #+#    #+#              #
#    Updated: 2026/06/17 12:02:49 by hhonorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    = ft_printf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf
SRC     = ft_printf.c \
          handle_conversion.c \
          ft_putnbr_base_fd.c \
		  ft_putnbr_count.c

OBJS    = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C fclean

re: fclean all

.PHONY: all clean fclean re
