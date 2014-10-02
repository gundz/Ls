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
CFLAGS = 	-Wall -Wextra -Werror

PATH_INC = 	includes/
PATH_OBJ =	 obj
PATH_SRC = 	srcs

SRC =		\
			main.c \

LIBPATH = libft/
LIBINC = $(LIBPATH)includes

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all: libft $(NAME)

$(NAME): namemes $(OBJ)
	@ $(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -I$(LIBINC) -I$(PATH_INC) \
	$(LIBPATH)libft.a -o $(NAME)
	@ echo " \033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/, %.c)
	@ echo -n .
	@ mkdir -p $(PATH_OBJ)
	@ $(CC) -c $^ -I$(PATH_INC) -I$(LIBINC) $(CFLAGS) -o $@

libft:
	@ make -C $(LIBPATH)

clean:
	@ make clean -C $(LIBPATH)
	@ rm -rf $(PATH_OBJ)
	@ echo "Cleaning $(NAME) \
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

fclean: clean
	@ make fclean -C $(LIBPATH)
	@ rm -rf $(NAME)
	@ echo "Fcleaning $(NAME) \
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

namemes :
	@ echo -n Compiling $(NAME)

re: fclean all

.PHONY: clean fclean re libft
