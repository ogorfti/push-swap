# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 13:17:09 by ogorfti           #+#    #+#              #
#    Updated: 2023/01/12 16:25:27 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS =	push_swap.c ft_opt1.c ft_opt2.c ft_opt3.c ft_utils1.c ft_utils2.c ft_sort3.c\
		ft_sort5.c ft_smallx.c ft_bigx.c ft_score.c ft_comn_instru.c ft_bigx_utils.c\
		ft_check_utils1.c ft_check_utils2.c ft_check_utils3.c ft_check_args.c ft_optimize.c\

SRCS_BONUS =	ft_check_args.c ft_check_utils1.c ft_check_utils2.c ft_check_utils3.c\
				ft_utils1.c ft_utils2.c checker.c get_next_line.c get_next_line_utils.c\
				checker_dependency.c ft_opt1.c ft_opt2.c ft_opt3.c ft_opt1_check.c\
				ft_opt2_check.c ft_opt3_check.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME) :	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
		
all : $(NAME)

clean :
		$(RM) $(NAME)

fclean : clean
		$(RM) $(NAME_BONUS)

bonus : $(SRCS_BONUS)
		$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

re :

.PHONY :
