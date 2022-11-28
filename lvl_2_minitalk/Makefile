# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 20:38:49 by nnuno-ca          #+#    #+#              #
#    Updated: 2022/11/27 23:15:02 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf
SERVER = server
CLIENT = client

SRCS = 
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = 
BONUS_OBJS = $(BONUS_SRCS:c=.o)

all: $(SERVER) $(CLIENT)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	$(RM) $(SERVER) $(CLIENT)
re: fclean all

bonus: 