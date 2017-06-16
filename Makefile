##
## Makefile for  in /home/sofiane/Documents/cpp_indie_studio
## 
## Made by sofiane
## Login   <sofiane@epitech.net>
## 
## Started on  Tue May 30 15:02:50 2017 sofiane
## Last update Fri Jun 16 02:15:43 2017 sofiane
##

GPP	=	g++

NAME	=	Bomberman

CPPFLAGS	+=	-I source/engine/window/
CPPFLAGS	+=	-I source/engine/event/
CPPFLAGS	+=	-I source/engine/world3d/
CPPFLAGS	+=	-I irrlicht/include/


LDFLAGS	=	-L irrlicht/lib -lIrrlicht -lGL -lX11 -lXxf86vm

XWINDOW	=	source/engine/window/
XEVENT	=	source/engine/event/
XSAMPLE	=	source/sample/
XWORLD3D=	source/engine/world3d/

SRC	=	$(XSAMPLE)main_window_world3d.cpp \
		$(XWINDOW)Window.cpp \
		$(XWORLD3D)world3d.cpp \
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
