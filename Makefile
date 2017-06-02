##
## Makefile for  in /home/sofiane/Documents/cpp_indie_studio
## 
## Made by sofiane
## Login   <sofiane@epitech.net>
## 
## Started on  Tue May 30 15:02:50 2017 sofiane
## Last update Fri Jun  2 13:46:48 2017 sofiane
##

GPP	=	g++

NAME	=	Bomberman

CPPFLAGS	+=	-I source/engine/window/
CPPFLAGS	+=	-I irrlicht/include/


LDFLAGS	=	-L lib/ -lIrrlicht -lGL -lX11 -lXxf86vm

XWINDOW	=	source/engine/window/
XSAMPLE	=	source/sample/

SRC	=	$(XSAMPLE)main_window.cpp \
		$(XWINDOW)Window.cpp

OBJ	=	$(SRC:.cpp=.o)


RM	=	rm -f

CPPFLAGS+=	-std=c++11 -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(GPP) $(OBJ) -o $(NAME) $(LDFLAGS)

install:	all

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all install clean fclean re
