##
## Makefile for  in /home/sofiane/Documents/cpp_indie_studio
## 
## Made by sofiane
## Login   <sofiane@epitech.net>
## 
## Started on  Tue May 30 15:02:50 2017 sofiane
## Last update Fri Jun  2 21:43:20 2017 sofiane
##

GPP	=	g++

NAME	=	Bomberman

CPPFLAGS	+=	-I source/engine/window/
CPPFLAGS	+=	-I source/engine/event/
CPPFLAGS	+=	-I irrlicht/include/


LDFLAGS	=	-L irrlicht/lib -lIrrlicht -lGL -lX11 -lXxf86vm

XWINDOW	=	source/engine/window/
XEVENT	=	source/engine/event/
XSAMPLE	=	source/sample/


SRC	=	$(XSAMPLE)main_event.cpp \
		$(XEVENT)eventReceiver.cpp \

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
