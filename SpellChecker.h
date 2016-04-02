/**
Name: Jeff McCullen and Emma Elliott
Date: March 16, 2016
Description:
*/

#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <string>
#include <list>
#include <map>


class SpellChecker
{
public:
	/**
	Construct a SpellChecker.
	*/
	SpellChecker(std::string lexiconFile);

	/**
	Get the edit distance for two words.

	@param firstWord The first word to compare.
	@param secondWord The second word to compare.
	@return The edit distance between firstWord and secondWord.
	*/
	static int editDistance(std::string firstWord,
		std::string secondWord);

	/**
	Determine wheater a word is spelled correctly

	@param word The word to determine if it is spelled correctly.
	@return True if word is spelled correctly.
	*/
	bool spelledCorrectly(std::string word);

	/**
	Get a list of suggested words for the word given the edit distance.

	@param word The word to make suggestions for.
	@param givenEditDistance The edit distance which determines which words
	can be contained in the returned list.
	@return A list of suggested words.
	*/
	std::list<std::string> suggestWords(std::string word, 
		int givenEditDistance);

	/**
	Destruct a SpellChecker.
	*/
	virtual ~SpellChecker();
private:
	// Node for the BK tree which stores the words.
	class BKNode
	{
	public:
		BKNode(std::string word);
		std::string Word;
		std::map<size_t, BKNode*> EditDistanceToChild;
	};

	/** Determine if a word is in the tree.

	@param word The word to determine if it is spelled correctly.
	@param pNode Pointer to current node.
	@return True if word is in the tree.
	*/
	bool lookup(std::string& word, BKNode* pNode, 
		int allowableEditDistance, 
		std::list<std::string>& listOfSuggestedWords);

	/**
	Insert word into BKTree.

	@param word Word to insert into the BKTree.
	@return True if the word was inserted (not a duplicate).
	*/
	virtual bool insert(const std::string& word);

	/**
	Helper function for insert in order to do recursive call.

	@param word Word to insert into th BKTree.
	@param pNode The current node.
	@return True if the word was inserted (not a duplicate).
	*/
	virtual bool insertAux(const std::string& word, BKNode*& pNode);

	/**
	Make the given word all uppercase.

	@param word The word to make uppercase.
	*/
	virtual void makeUpperCase(std::string& word);

	/**
	Destroy the spell checker and any allocated memory in the
	tree of words using a post order traversal.

	@param pNode The current node.
	*/
	virtual void destroySpellChecker(BKNode*& pNode);

	// Pointer to the root node of the word tree.
	BKNode* _pRoot;
};

#endif // SPELL_CHECKER_H
