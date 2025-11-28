# Compiler und Flags
CC = gcc
CFLAGS = -g -ansi -pedantic-errors -Wall

# Hauptziel
a52: a52.o textfun.o
	$(CC) $(CFLAGS) -o a52 a52.o textfun.o

# Objektdateien
a52.o: a52.c textfun.h
	$(CC) $(CFLAGS) -c a52.c

textfun.o: textfun.c textfun.h
	$(CC) $(CFLAGS) -c textfun.c

# Aufräumen
clean:
	rm -f textfun.o a52.o myprogramm