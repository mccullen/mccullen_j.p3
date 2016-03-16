# Name: Jeff McCullen and Emma Elliott
# Date: February 10, 2016
# Description: Tic-tac toe makefile

CC = g++
CFLAGS = -g #-Wall

all: spellCheck

spellCheck: spellCheck.o SpellChecker.o
	$(CC) $(CFLAGS) -o spellCheck spellCheck.o SpellChecker.o

SpellChecker.o: SpellChecker.cpp
	$(CC) $(CFLAGS) -c SpellChecker.cpp

clean:
	rm -f spellCheck *.o *~