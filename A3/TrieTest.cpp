/*
Auth: Justin Francis
Class: CS3505
Assign: A3 Trie
Created: 9/15/19
Version: 0.1
Modified:

*/
#include "Trie.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
  //check if valid number of inputs
  if(argc != 3)
  {
    if(argc < 3)
    {
      cout << "Too few arguments given in command line. Please revise.\n";
    }
    else
    {
      cout << "Too many arguments given in command line. Please revise.\n";
    }
    return 1;
  }

  //create vars
  Trie dictionary;
  fstream wordsToAddFile;
  fstream wordsToCheckFile;

  //add words to trie
  wordsToAddFile.open(argv[1]);

  if(!wordsToAddFile.is_open()) //check if wordsToAddFile is legit
  {
    cout << "The first file  name is invalid. Please revise.\n";
    return 1;
  }
  else
  {
    string word;
    while(getline(wordsToAddFile, word)) //pull all words from wordsToAddFile
    {
      dictionary.addAWord(word);
    }
    wordsToAddFile.close();
  }

  //check words in Trie
  wordsToCheckFile.open(argv[2]);

  if(!wordsToCheckFile.is_open()) //check if wordsToAddFile is legit
  {
    cout << "The second file name is invalid. Please revise.\n";
    return 1;
  }
  else
  {
    string word;
    while(getline(wordsToCheckFile, word)) //pull all words from wordsToAddFile
    {
      if(dictionary.isAWord(word))
      {
        cout << word << " is found.\n";
      }
      else
      {
        //TODO: print list of words with "word" as prefix
        cout << word << " is not found, did you mean TODO:\n";
      }
    }
    wordsToCheckFile.close();
  }

  //TODO: excercise rule-of-three

}
