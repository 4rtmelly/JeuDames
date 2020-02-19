

CC=gcc
SRC=deplacement.c initialisation.c manger.c conditionsFin.c main.c
OBJ=$(SRC:.c=.o)
FLAGS=-Wall

JeuDames:    $(OBJ) 
	$(CC) -o $@ $(OBJ)

%.o:	%.c dames.h
	$(CC) -c $< $(CFLAGS)



clean:
	rm *.o *~ core
