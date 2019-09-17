# Auth: Justin Francis
# Class: CS3505
# Assign: A3 Trie
# Created: 9/15/19
# Version: 0.1
# Modified:
#
#
# Description: A makefile because command line is hard

CC = g++
CFLAGS = -Wall -fsanitize=undefined -fsanitize=address -g -std=c++11

TrieTest: Trie.o TrieTest.o
	$(CC) $(CFLAGS) -o TrieTest Trie.o TrieTest.o

Trie.o: Trie.cpp #Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

TrieTest.o: TrieTest.cpp
	$(CC) $(CFLAGS) -c TrieTest.cpp



#clean and test
clean:
	rm TrieTest *.o

test:
	./TrieTest "sample text: ab abusu ad usum non valet consequentia decessit sine prole superstite haha";
