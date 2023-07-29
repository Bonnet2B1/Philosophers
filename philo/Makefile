# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 16:59:43 by edelarbr          #+#    #+#              #
#    Updated: 2023/07/25 17:21:58 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo

# NAME_BONUS	:=	pipex_bonus

# ------------------------------ Sources -----------------------------

SRCS :=			srcs/*.c\

OBJS		:=	$(SRCS:.c=.o)
# OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)

.c.o:
	@ $(CC) $(FLAGS) -c $< -o $(<:.c=.o)

# ------------------------------ Flags -------------------------------

CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g3 -fsainitize=address fsanitize=thread

# ------------------------------ Colors ------------------------------

# Colors

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ Programme ---------------------------


all:			$(NAME)

# bonus:			$(NAME_BONUS)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS)
				@ echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

# $(NAME_BONUS):	$(OBJS_BONUS)
# 				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME_BONUS) $(CLR_RMV)..."
# 				@ $(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)
# 				@ echo "$(GREEN)$(NAME_BONUS) created $(CLR_RMV)✔️"


# --  ---------------------------- Rules -----------------------------

clean:
				@ $(RM) $(OBJS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
				@ echo "$(RED)Deleting $(CYAN)$(NAME_BONUS) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
				@ echo "$(RED)Deleting $(CYAN)$(NAME_BONUS) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all bonus clean fclean re