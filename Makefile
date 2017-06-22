##
## Makefile for  in /home/sofiane/Documents/cpp_indie_studio
## 
## Made by sofiane
## Login   <sofiane@epitech.net>
## 
## Started on  Tue May 30 15:02:50 2017 sofiane
## Last update Thu Jun 22 18:31:23 2017 sofiane
##

GPP	=	g++

NAME	=	Bomberman
NAME2	=	Menu

CPPFLAGS	+=	-I source/engine/window/
CPPFLAGS	+=	-I source/player/
CPPFLAGS	+=	-I source/common/
CPPFLAGS	+=	-I source/engine/event/
CPPFLAGS	+=	-I source/engine/world3d/
CPPFLAGS	+=	-I source/engine/menu/
CPPFLAGS	+=	-I source/engine/collision/
CPPFLAGS	+=	-I source/engine/test/
CPPFLAGS	+=	-I irrlicht/include/


LDFLAGS	=	-L irrlicht/lib -lIrrlicht -lGL -lX11 -lXxf86vm

XWINDOW	=	source/engine/window/
XEVENT	=	source/engine/event/
XSAMPLE	=	source/sample/
XWORLD3D=	source/engine/world3d/
XMENU	=	source/engine/menu/
XCOL	=	source/engine/collision/
XAPP	=	source/app/
XPLAYER =	source/player/
XTESTE	=	source/engine/test/


SRC	=	$(XSAMPLE)main_event.cpp \
		$(XWINDOW)Window.cpp \
		$(XWORLD3D)world3d.cpp \
		$(XEVENT)myEventManager.cpp \
		$(XCOL)collision.cpp

SRC2	=	$(XSAMPLE)main_menu.cpp \
		$(XWINDOW)Window.cpp \

OBJ	=	$(SRC:.cpp=.o)

OBJ2	=	$(SRC2:.cpp=.o)


RM	=	rm -f

CPPFLAGS+=	-std=c++11 -g

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJ)
		$(GPP) $(OBJ) -o $(NAME) $(LDFLAGS)
		$(GPP) $(OBJ2) -o $(NAME2) $(LDFLAGS)

install:	all

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJ2)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all install clean fclean re
