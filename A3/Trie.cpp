/*
Auth: Justin Francis
Class: CS3505
Assign: A3 Trie
Created: 9/15/19
Version: 0.1
Modified:

*/

#include "Trie.h"
#include <vector>
#include <string>
using namespace std;
//TODO: make wrapper class for root node init
#define ALPHABET_SIZE 26
#define ASCII_START_VAL 97
// #define DEBUGADD
#define DEBUG
#ifdef DEBUG
  #include <iostream>
#endif


Trie::Trie()
{
  for(int i = 0; i < ALPHABET_SIZE; i++)
  {
    alph_[i] = nullptr;
  }
  isEndOfWord = false;
}
Trie::Trie(const Trie& toCopy)
{
  for(int i = 0; i < ALPHABET_SIZE; i++)
  {
    alph_[i] = nullptr;
    if(toCopy.alph_[i])
    {
      alph_[i] = new Trie(*toCopy.alph_[i]);
    }
  }
}

Trie::~Trie()
{
  delete alph_;
}

Trie& Trie::operator=(Trie other)
{
  std::swap(alph_, other.alph_);
  std::swap(isEndOfWord, other.isEndOfWord);

  return *this;
}

/*
A method addAWord that accepts a std::string and returns void. The word
passed into the method should be added to the Trie. Duplicate adds should
not change the Trie. You may assume that the word is only made up of
lower-case characters from a-z.
*/

void Trie::addAWord(string word)
{
  if(!word.empty())
  {
    char c = word[0];
#ifdef DEBUGADD
cout << "word: " << word << endl;
cout << "char: " << c << endl;
#endif
    int idx = c - ASCII_START_VAL;
    if(!alph_[idx])
    {
      alph_[idx] = new Trie();
    }
    alph_[idx]->addAWord(word.substr(1, word.length()));
  }
  else
  {
    isEndOfWord = true;
  }
}

/*
A method isAWord that accepts a std::string and returns bool. The argument
is a string assumed to be made up of characters 'a'-'z'. If the word is
found in the Trie, the method should return true, otherwise return
false.  A Trie should report that an empty string is not in the Trie.
*/
bool Trie::isAWord(string word)
{
  //TODO:
  bool flag;
  if(word.empty())
  {
    flag = isEndOfWord;
  }
  else
  {
    char c = word[0];
    int idx = c - ASCII_START_VAL;
    if(alph_[idx])
    {
      flag = alph_[idx]->isAWord(word.substr(1, word.length()));
    }
    else {flag = false;}
  }
  return flag;
}


/*
A method allWordsStartingWithPrefix that accepts a std::string and returns
a vector<std::string> that contains all the words in the Trie that start
with the passed in argument prefix string. A word that is just the prefix
is acceptable. An empty prefix should return all words in the Trie.
*/
vector<string> Trie::allWordsStartingWithPrefix(string prefix)
{
  vector<string> vectorOfWords;
  if(prefix.empty())
  {
    //TODO:
  }
  else
  {
    Trie* nodeAtEndOfPrefix;
    if(returnWord(prefix, nodeAtEndOfPrefix))
    {
      recursiveAllWordsStartingWithPrefix(prefix, word, vectorOfWords);
    }
  }

  return vectorOfWords;
}

//helper method
Trie* returnWord(string word)
{

}

void recursiveAllWordsStartingWithPrefix(string prefix, string word, vector<string>& vectorOfWords)
{
  for(int i = 0; i < ALPHABET_SIZE; i++)
  {
    if(isEndOfWord)
    {
      vectorOfWords.insert(word);
    }
    else(alph_[i])
    {
      recursiveAllWordsStartingWithPrefix(prefix.substr(1,prefix.length()), word.append((char)(i+ASCII_START_VAL)), vectorOfWords);
    }
  }
}
