CC = gcc
CFLAGS = -Wall
INFLAGS = -I../include
SRC = aleaAbr.c exportAbr.c hauteurAbr.c importAbr.c parcoursAbr.c rechercheAbr.c rotationAbr.c
OBJ = $(SRC:.c=.o)
LIB = libabr.a

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INFLAGS)

clean:
	rm -f $(LIB) $(OBJ)

.PHONY: clean
