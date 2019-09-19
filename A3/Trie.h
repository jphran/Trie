/*
Auth: Justin Francis
Class: CS3505
Assign: A3 Trie
Created: 9/15/19
Version: 0.1
Modified:

*/

#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>
#define ALPHABET_SIZE 26

class Trie
{
  Trie* alph_[ALPHABET_SIZE];
  bool isEndOfWord;

private:
  bool returnWord(std::string word, Trie* nodeAtEndOfPrefix);
  // void recursiveAllWordsStartingWithPrefix(std::string word, std::vector<std::string>& vectorOfWords, Trie* node);
    void recursiveAllWordsStartingWithPrefix(std::string word, std::vector<std::string>& vectorOfWords);
public:
  Trie();

  Trie(const Trie& toCopy);

  ~Trie();

  Trie& operator=(Trie other);

  void addAWord(std::string word);

  bool isAWord(std::string word);

  std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);
};
#endif
