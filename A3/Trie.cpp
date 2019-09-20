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
  isEndOfWord = toCopy.isEndOfWord;

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
  for(int i = 0; i < ALPHABET_SIZE; i++)
  {
    delete alph_[i];
  }

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
  Trie* currentNode = this;

  //travers prefix
  for(string::iterator iter = prefix.begin(); iter != prefix.end(); ++iter)
  {
    int idx = *iter - ASCII_START_VAL; //convert ascii to index number
    if(currentNode->alph_[idx]) //if branch exists
    {
      if(currentNode->isEndOfWord)
      {
        vectorOfWords.push_back(prefix); //if prefix is a word, add it
      }
      currentNode = currentNode->alph_[idx]; //set new pointer
    }
  }

  //if the prefix does not exist in trie
  if(currentNode != this){
    currentNode->recursiveAllWordsStartingWithPrefix(prefix, vectorOfWords);
  }

  return vectorOfWords;
}


//helper to recursiely grab words from trie
//takes in the prefix and the vector of strings to return
void Trie::recursiveAllWordsStartingWithPrefix(string word, vector<string>& vectorOfWords)
{
  for(int i = 0; i < ALPHABET_SIZE; i++) //go through every possible branch
  {
    string postfix = ""; //create postfix for each root in new trie
    if(alph_[i]) //if branch exists
    {
      postfix.push_back((i + ASCII_START_VAL)); //add branch name to word
      if(alph_[i]->isEndOfWord)
      {
        vectorOfWords.push_back(word + postfix); //if at end of branch, add word to vector
      }
      alph_[i]->recursiveAllWordsStartingWithPrefix((word + postfix), vectorOfWords); //call recursively
    }
  }
}
