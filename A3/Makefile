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
TRIELIB = .

TrieTest: Trie.o TrieTest.o
	$(CC) $(CFLAGS) -o TrieTest Trie.o TrieTest.o -I$(TRIELIB) -L$(TRIELIB)

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

TrieTest.o: TrieTest.cpp
	$(CC) $(CFLAGS) -c TrieTest.cpp



#clean and test
clean:
	rm TrieTest *.o

test:
	./TrieTest "testAdd.txt" "testIsAWord.txt"

debug:
	gdb ./TrieTest "testAdd.txt" "testIsAWord.txt"
