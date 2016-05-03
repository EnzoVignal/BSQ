##
## Makefile for maefile in /home/nonnen_p/rendu/CPE_2015_Pushswap
## 
## Made by Paul NONNENMACHER
## Login   <nonnen_p@epitech.net>
## 
## Started on  Mon Nov  9 17:34:34 2015 Paul NONNENMACHER
## Last update Wed Jan  6 15:18:23 2016 paul nonnenmacher
##

CC	= cc -W -Wall

RM	= rm -f

SRC	= bsq.c\
	  my_print.c\
	  get_next_line.c\
	  my_getnbr.c\
	  algo.c\
	  check.c\

OBJ	= $(SRC:.c=.o)

NAME	= bsq

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cl: $(NAME) clean
