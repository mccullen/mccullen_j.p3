#include <string>
#include "SpellChecker.h"
/*Testing!*/

/**
Construct a SpellChecker.
*/
SpellChecker::SpellChecker(std::string lexiconFile)
{
}

/**
Get the edit distance for two words.

@param firstWord The first word to compare.
@param secondWord The second word to compare.
@return The edit distance between firstWord and secondWord.
*/
int SpellChecker::editDistance(std::string firstWord,
	std::string secondWord)
{
	
}

/**
Determine wheater a word is spelled correctly

@param word The word to determine if it is spelled correctly.
@return True if word is spelled correctly.
*/
bool SpellChecker::spelledCorrectly(std::string word)
{
}

/**
Get a list of suggested words for the word given the edit distance.

@param word The word to make suggestions for.
@param givenEditDistance The edit distance which determines which words
can be contained in the returned list.
@return A list of suggested words.
*/
std::list<std::string> SpellChecker::suggestWords(std::string word, 
	int givenEditDistance)
{
}

/**
Destruct a SpellChecker.
*/
SpellChecker::~SpellChecker()
{
}
