# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 13:17:09 by ogorfti           #+#    #+#              #
#    Updated: 2022/12/26 12:26:35 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c\
		opt.c\
		ft_algo3.c\
		ft_big_algo.c\

OBJS =  $(SRCS:.c=.o)

CC = cc

OUT = a.push

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

RM = rm -f

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re :	fclean all

push :	all clean

me1 : push
		$(CC) $(CFLAGS) $(NAME) -o $(OUT)

me : me1
		$(RM) $(NAME)
	