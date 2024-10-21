# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joanavar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 16:29:09 by joanavar          #+#    #+#              #
#    Updated: 2024/10/21 16:30:49 by joanavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CFLAGS	= -Wall -Werror -Wextra #-g -fsanitize=thread

OBJ_DIR = obj/
SRC_DIR = src/

SOURCES =	main.c \
			parsing.c \
			utils.c \
			init.c \
			routine.c

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c philo.h Makefile
	@cc $(CFLAGS) -c $< -o $@
	@echo Compiling $< ...

$(NAME): $(OBJECTS)
	@cc $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32mphilosophers compiled\033[0m"

$(OBJ_DIR):
	-@mkdir -p $(OBJ_DIR);

clean :
	@rm -fr $(OBJ_DIR)
	@echo cleaning objects

fclean : clean
	@rm -f $(NAME)
	@echo cleaning \'$(NAME)\' file
	
re: fclean all

.PHONY: all clean fclean re
