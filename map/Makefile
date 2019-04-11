##
## Makefile for  in /home/charra_s/PSU_2015_philo
##
## Made by Charrad Sofiane
## Login   <charra_s@epitech.net>
##
## Started on  Sun Mar 13 20:32:55 2016 Charrad Sofiane
## Last update Sun Jun  5 20:57:01 2016 daoud_c
##

SRC		=	Splash.cpp
#SRC	=	MyGu.cpp
NAME		=	GUI

OBJ		=	$(SRC:.c=.o)

CC		=	g++

# CFLAGS  +=  -lIrrlicht -lXxf86vm -lXrandr -lGL -lGLU -lXi -03
# CFLAGS  +=  -Werror
# CFLAGS  += -I./include
#LDFLAGS  = -lIrrlicht -lXxf86vm -lXrandr -lGL -lGLU -lXi
#LDFLAGS = -L/usr/X11R6/lib -lGL -lXxf86vm -lXext -lX11 -lpng -ljpeg -lIrrlicht -Wdeprecated-declarations
LDFLAGS = -lGL -lXxf86vm -lXext -lX11 -lIrrlicht

INCLUDES	=	-I.include/irrlicht

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(LDFLAGS) -lIrrlicht

all: $(NAME)

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf *#

fclean: clean
	rm -rf $(NAME)

re: fclean all
