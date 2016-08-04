#include <iostream>
#include <string>
using namespace std;
class TrieNode{
public:
	// Initialize your data structure here.
	char data;
	class TrieNode	*child[26];
	int freq;
	TrieNode(){
		data = '0';
		freq = 0;
		for (auto &i : child)
			i = NULL;
	}
	TrieNode(char x):data(x),freq(0){
		for (auto &i : child)
			i = NULL;
	}
};
class Trie{
public:
	Trie(){
		root = new TrieNode();
	}
	// Inserts a word into the trie.
	void insert(string word){
		if (word.length() == 0) return;
		TrieNode *p = root;
		for (size_t i = 0; i < word.length(); ++i){
			int k = word[i] - 'a';
			if (p->child[k] == NULL)
				p->child[k] = new TrieNode(word[i]);
			p = p->child[k];
			p->freq++;
		}
	}
	// Returns if the word is in the trie.
	bool search(string word){
		if (word.length() == 0)  return false;
		TrieNode *p = root;
		for (size_t i = 0; i < word.length(); ++i){
			int k = word[i] - 'a';
			if (p->child[k] == NULL)
				return false;
			p = p->child[k];
		}
		//ab ad£¬if freq of a is 2, a is not in Trie; 
		//if freq is 3, a is in Trie
		int count = 0;
		for (size_t i = 0; i < 26; ++i)
			if (p->child[i] != NULL)
				count+=p->child[i]->freq;
		if (p->freq == count)
			return false;
		return true;
	}
	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix){
		if (prefix.length() == 0) return false;
		TrieNode *p = root;
		for (size_t i = 0; i < prefix.length(); ++i){
			int k = prefix[i] - 'a';
			if (p->child[k] == NULL)
				return false;
			p = p->child[k];
		}
		return true;
	}
private:
	TrieNode *root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");