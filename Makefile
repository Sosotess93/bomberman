##
## Makefile for  in /home/sofiane/Documents/cpp_indie_studio
## 
## Made by sofiane
## Login   <sofiane@epitech.net>
## 
## Started on  Tue May 30 15:02:50 2017 sofiane
## Last update Thu Jun  1 15:25:11 2017 sofiane
##

NAME	=	Bomberman

SRC	=	engine/window/main.cpp \
		engine/window/Window.cpp

OBJ	=	$(SRC:.cpp=.o)

GPP	=	g++

RM	=	rm -f

CPPFLAGS+=	-std=c++11 -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(GPP) -o $(NAME) $(OBJ) -L lib/ -lIrrlicht -lGL -lX11 -lXxf86vm

install:	all

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all install clean fclean re
