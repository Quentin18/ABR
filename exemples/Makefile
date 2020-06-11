CC = gcc
CFLAGS = -Wall
INFLAGS = -I../include
LIBFLAGS = -L../src -labr
EXEC = exemple1 exemple2 exemple3 exemple4 analyseHauteur

all: $(EXEC)

exemple1: exemple1.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

exemple2: exemple2.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

exemple3: exemple3.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

exemple4: exemple4.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

analyseHauteur: analyseHauteur.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INFLAGS)

clean:
	rm -f $(EXEC) *.o *.dot *.csv

.PHONY: clean
