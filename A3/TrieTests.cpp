/*
Palani Thangaraj
u0913877
A3: TrieTest

 This holds the main for Trie, it also serves as a testing class to test the
 various methods and functionality of the Trie class
*/

#include "Trie.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


//********************************IS WORD TESTS***************************

//determine if an empty Trie contains anything or empty string
TEST (isAWordTest, emptyTrie)
{
  Trie* t = new Trie();

  ASSERT_FALSE (t->isAWord("test"));
  ASSERT_FALSE(t->isAWord(""));

  delete t;
}

//detemine if affirmative base case works
TEST(isAWordTest, existingWord)
{
  Trie* t = new Trie();
  t->addAWord("exist");

  ASSERT_TRUE(t->isAWord("exist"));

  delete t;
}

//determine if negative base case works
TEST(isAWordTest, notAWord)
{
  Trie* t = new Trie();
  t->addAWord("word");

  ASSERT_TRUE(t->isAWord("word"));
  ASSERT_FALSE(t->isAWord("notword"));
  ASSERT_FALSE(t->isAWord("w"));

  delete t;

}

//determine if edge cases pass
TEST(isAWordTest, edgeCase)
{
  Trie* t = new Trie();
  t->addAWord("");

  ASSERT_FALSE(t->isAWord(""));

  delete t;
}


//********************************ADD WORD TESTS*************************
//affirmative base case
TEST (addAWordTest, addSingleWord)
{
  Trie* t = new Trie();
  string word = "test";
  t->addAWord(word);

  ASSERT_TRUE (t->isAWord(word));

  delete t;
}

//robust affirmative base case
TEST (addAWordTest, addMultipleWords)
{
  Trie* t = new Trie();
  t->addAWord("testa");
  t->addAWord("testb");
  t->addAWord("testc");
  ASSERT_TRUE (t->isAWord("testa"));
  ASSERT_TRUE (t->isAWord("testb"));
  ASSERT_TRUE (t->isAWord("testc"));
  delete t;
}

//negative base case
TEST (addAWordTest, checkWrongWord)
{
  Trie* t = new Trie();
  t->addAWord("testa");
  t->addAWord("testb");
  t->addAWord("testc");
  ASSERT_FALSE (t->isAWord("test"));
  delete t;
}

//edge cases
TEST(addAWordTest, edgeCase)
{
  Trie* t = new Trie();
  t->addAWord("");
  t->addAWord("");
  t->addAWord("test");
  t->addAWord("test");

  std::vector<std::string> returned = t->allWordsStartingWithPrefix("");

  EXPECT_EQ(1, returned.size());

  delete t;
}

//*****************************RULE OF THREE TESTS ****************************

//Constructor
TEST(constructorTest, stackTest)
{
  Trie t;

  ASSERT_FALSE(t.isAWord(""));

  t.addAWord("stack");

  ASSERT_TRUE(t.isAWord("stack"));
}

TEST(constructorTest, heapTest)
{
  Trie* t = new Trie();

  ASSERT_FALSE(t->isAWord(""));

  t->addAWord("heap");

  ASSERT_TRUE(t->isAWord("heap"));
}

//Destructor
//TODO: write this test
TEST(destructorTest, doubleFree)
{
  Trie* t = new Trie();

  delete t;
  // delete t;

  // t->addAWord("");
}


TEST (prefixTest, checkPrefixMultipleWords3)
{
  Trie* t = new Trie();
  t->addAWord("cat");
  t->addAWord("car");

  vector<string> input;

  input.push_back("car");
  input.push_back("cat");


  vector<string> output = t->allWordsStartingWithPrefix("ca");

  //ASSERT_EQ (2, output.size());
  ASSERT_TRUE (input == output);
  delete t;
}

TEST(equalOperator, checkTrueAndFalse){
    Trie* t1 = new Trie();
    t1->addAWord("correct");

    Trie* t2 = new Trie();

    *t2 = *t1;

    ASSERT_TRUE(t2->isAWord("correct"));
    ASSERT_FALSE(t2->isAWord("incorrect"));

    t2->addAWord("incorrect");

    ASSERT_TRUE(t2->isAWord("incorrect"));
    ASSERT_FALSE(t1->isAWord("incorrect"));

    delete t1;
    delete t2;
}

//copy constructor
TEST(copyConstructorTest, baseCase)
{
  Trie t;
  t.addAWord("copythis");

  Trie copy(t);

  EXPECT_TRUE(copy.isAWord("copythis"));
}
