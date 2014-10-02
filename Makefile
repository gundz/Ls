# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/24 18:59:31 by fgundlac          #+#    #+#              #
#    Updated: 2014/03/14 04:21:03 by fgundlac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ls

CC =  		clang
CFLAGS = 	-g

PATH_INC = 	includes/
PATH_OBJ =	 obj
PATH_SRC = 	srcs

SRC =		\
			lst_create_elem.c \
			lst_push_back.c \
			lst_sort.c \
			ft_putstr.c \
			ft_strdup.c \
			ft_strcmp.c \
			ft_strcat.c \
			main.c \
			store_dir.c \
			show.c \
			error.c \

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all: $(NAME)

$(NAME): namemes $(OBJ)
	@ $(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -I $(PATH_INC) -o $(NAME)
	@ echo " \033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/, %.c)
	@ echo -n .
	@ mkdir -p $(PATH_OBJ)
	@ $(CC) -c $^ -I$(PATH_INC) $(CFLAGS) -o $@

clean:
	@ rm -rf $(PATH_OBJ)
	@ echo "Cleaning $(NAME) \
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "Fcleaning $(NAME) \
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

namemes :
	@ echo -n Compiling $(NAME)

re: fclean all

.PHONY: clean fclean re
