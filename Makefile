# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 13:17:09 by ogorfti           #+#    #+#              #
#    Updated: 2023/01/10 21:45:13 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS =	push_swap.c ft_opt1.c ft_opt2.c ft_opt3.c ft_utils1.c ft_utils2.c ft_sort3.c\
		ft_sort5.c ft_smallx.c ft_bigx.c ft_score.c ft_comn_instru.c ft_bigx_utils.c\
		ft_check_utils1.c ft_check_utils2.c ft_check_utils3.c ft_check_args.c

SRCS_B =	ft_opt1.c ft_opt2.c ft_opt3.c ft_utils1.c ft_utils2.c ft_sort3.c\
		ft_sort5.c ft_smallx.c ft_bigx.c ft_score.c ft_comn_instru.c ft_bigx_utils.c\
		ft_check_utils1.c ft_check_utils2.c ft_check_utils3.c ft_check_args.c

SRCS_BONUS = push_swap_bonus.c\

OBJS =  $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
all : $(NAME)

clean :
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
		$(RM) $(NAME) $(NAME_BONUS)

re :	fclean bonus

bonus : all $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(SRCS_B) -o $(NAME_BONUS)

me : all clean

b : bonus clean