# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 16:59:43 by edelarbr          #+#    #+#              #
#    Updated: 2023/08/15 16:20:22 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo

# ------------------------------ Sources -----------------------------

SRCS		:=	srcs/philo.c \
				srcs/utils/print.c \
				srcs/utils/parser.c \
				srcs/utils/destroy_simulation.c \
				srcs/utils/struct_init.c \
				srcs/utils/stop_checker.c \
				srcs/utils/time.c \
				srcs/utils/routine.c \
				srcs/utils/monitoring.c \
				srcs/utils/philosopers_actions.c \
				srcs/lib/ft_isdigit.c \
				srcs/lib/ft_strlen.c \
				srcs/lib/ft_freeall.c \
				srcs/lib/ft_putstr.c \
				srcs/lib/ft_atoi.c \

OBJS		:=	$(SRCS:.c=.o)

.c.o:
	@ $(CC) $(FLAGS) -c $< -o $(<:.c=.o)

# ------------------------------ Flags -------------------------------

CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror

# ------------------------------ Colors ------------------------------

# Colors

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ Compilation -------------------------


all:			$(NAME)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(SRCS)
				@ echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

# -------------------------------- Rules -----------------------------

clean:
				@ $(RM) $(OBJS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all bonus clean fclean re
