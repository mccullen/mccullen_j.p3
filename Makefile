# Name: Jeff McCullen and Emma Elliott
# Date: February 10, 2016
# Description: Tic-tac toe makefile

CC = g++
CFLAGS = -g -Wall

all: spellCheck.exe

spellCheck.exe: spellCheck.o SpellChecker.o
	$(CC) $(CFLAGS) -o spellCheck.exe spellCheck.o SpellChecker.o

SpellChecker.o: SpellChecker.cpp SpellChecker.h
	$(CC) $(CFLAGS) -c SpellChecker.cpp

spellCheck.o: spellCheck.cpp SpellChecker.h
	$(CC) $(CFLAGS) -c spellCheck.cpp

clean:
	rm -f spellCheck.exe *.o *~
