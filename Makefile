# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 18:25:25 by alisseye          #+#    #+#              #
#    Updated: 2025/03/02 14:01:32 by alisseye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OPS = srcs/operations/operations.c \
	srcs/operations/pa.c srcs/operations/pb.c \
	srcs/operations/ra.c srcs/operations/rb.c \
	srcs/operations/rr.c srcs/operations/rra.c \
	srcs/operations/rrb.c srcs/operations/rrr.c \
	srcs/operations/sa.c srcs/operations/sb.c \
	srcs/operations/ss.c

SRCS = srcs/main.c srcs/utils.c ${OPS} \
	srcs/push_swap.c srcs/sort.c \
	srcs/calculate_moves.c srcs/utils_moves.c \
	srcs/utils_sort.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -Llibft -lft -I includes -I libft

$(LIBFT):
	make -s -C libft bonus -I includes

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I includes -I libft

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -s clean -C libft

fclean: clean
	rm -f $(NAME)
	make -s fclean -C libft

re: fclean all

.PHONY: all clean fclean re
	