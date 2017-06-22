##
## Makefile for  in /home/sofiane/Documents/cpp_indie_studio
## 
## Made by sofiane
## Login   <sofiane@epitech.net>
## 
## Started on  Tue May 30 15:02:50 2017 sofiane
## Last update Thu Jun 22 19:58:42 2017 sofiane
##

GPP	=	g++

NAME	=	Bomberman
NAME1	=	Menu

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


SRCS	=	$(XSAMPLE)main_event.cpp \
		$(XWINDOW)Window.cpp \
		$(XWORLD3D)world3d.cpp \
		$(XEVENT)myEventManager.cpp \
		$(XCOL)collision.cpp

SRCS1	=	$(XWINDOW)Window.cpp \
		$(XMENU)menu.cpp \
		$(XSAMPLE)main_menu.cpp \

OBJS	=	$(SRCS:.cpp=.o)

OBJS1	=	$(SRCS1:.cpp=.o)


RM	=	rm -f

CPPFLAGS+=	-std=c++11 -g

all:		$(NAME) $(NAME1)

$(NAME):	$(OBJS)
		$(GPP) $(OBJS) -o $(NAME) $(LDFLAGS)

$(NAME1):	$(OBJS1)
		$(GPP) $(OBJS1) -o $(NAME1) $(LDFLAGS)

clean:
		$(RM) $(OBJS) $(OBJS1)

fclean:		clean
		$(RM) $(NAME) $(NAME1)

re:		fclean all

.PHONY:		all install clean fclean re
