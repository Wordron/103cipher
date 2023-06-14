##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC    =	main.c 	\
			crypt.c 	\
			decrypt.c	\
			my_strlen.c	\
			product_of_matrixes.c	\
			display.c	\
			get_matrix_message.c	\
			my_str_isalpha.c	\


OBJ    =    $(SRC:.c=.o)

NAME	=	103cipher

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lm

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
