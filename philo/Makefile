# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 21:23:00 by yachehbo          #+#    #+#              #
#    Updated: 2022/03/27 15:44:02 by yachehbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = fill.c init.c observer.c philo.c philo_utils.c routine.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ./philo.h $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re