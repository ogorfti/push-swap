# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 13:17:09 by ogorfti           #+#    #+#              #
#    Updated: 2023/01/02 22:30:01 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c\
		ft_opt.c\
		ft_utils.c\
		ft_sort3.c\
		ft_sort5.c\
		ft_smallx.c\
		ft_checker.c\
		ft_bigx.c\

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
	