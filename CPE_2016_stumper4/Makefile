##
## Makefile for Makefile in /home/jeremy.elkaim/CPE_2016_stumper4
## 
## Made by jeremy elkaim
## Login   <jeremy.elkaim@epitech.net>
## 
## Started on  Wed May 10 14:19:04 2017 jeremy elkaim
## Last update Wed May 10 17:13:01 2017 jeremy elkaim
##

CC	=	gcc -g3

RM	=	rm -rf

NAME	=	gameoflife

CFLAGS	=	-W -Wextra -I include/

SRC	=	src/main.c	\
		src/str.c	\
		src/read_file.c	\
		src/algo.c	\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
