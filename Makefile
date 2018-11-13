#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolinko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 13:28:37 by akolinko          #+#    #+#              #
#    Updated: 2018/06/08 23:12:24 by hmuravch         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

NOC = \x1b[0m
OKC = \x1b[32m
ERC = \x1b[31m
WAC = \x1b[33m


SRC =  fillit.c cordinates.c create_map.c algorithm.c validation.c ft_check.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -l ft -I libft -L libft 
	@echo "$(OKC)FILLIT:\tFillit ready$(NOC)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I libft
	@echo "$(WAC)FILLIT:\tObject was created$(NOC)"

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "$(ERC)FILLIT:\tObjects were deleted$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "$(ERC)FILLIT:\tFillit was deleted$(NOC)"

re: fclean all
