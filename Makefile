##
## Makefile for indie in /home/sivaku_v/rendu/Bomberman_v2
##
## Made by Vituzan Sivakumaran
## Login   <sivaku_v@epitech.net>
##
## Started on  Sat Jun  4 19:16:09 2016 Vituzan Sivakumaran
## Last update Sun Jun  5 23:32:49 2016 daoud_c
##

NAME=		Bomberman

SRC=		main.cpp \
		menu.cpp \
		MenuEvent.cpp \
		game.cpp \
		perso.cpp \
		maps.cpp \
		bomb.cpp \
		init.cpp \
		eventReceiver.cpp

OBJ=		$(SRC:.cpp=.o)

GCC=		g++

RM=		rm -f

CPPFLAGS+=	-std=c++11 -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(GCC) -o $(NAME) $(OBJ) -L lib/ -lIrrlicht -lGL -lX11 -lXxf86vm -lSDL_mixer -lSDL -lpthread

install:	all

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
