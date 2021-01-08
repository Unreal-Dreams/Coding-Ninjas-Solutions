#include<bits/stdc++.h>
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
    bool search(string word , TrieNode* root)
    {
        if(word.size()==0)
        {
            if(root!=NULL)
            {
                return true;
            }
            return false;
        }
        int index = word[0] - 'a';
        if(root->children[index]==NULL)
        {
            return false;
        }
        return search(word.substr(1),root->children[index]);
    }
    void insertWord(string word , TrieNode* root)
	{
		// base case...
		if(word.size()==0)
		{
			root->isTerminal=true;
			return;
		}
		
		//small calculation...
		int index = word[0] - 'a';
		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			child = root->children[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		
		//recursive call...
		insertWord(word.substr(1),child);
	}
    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i = 0 ; i < words.size() ; i++)
        {
            for(int j = 0 ; j < words[i].length() ; j++)
            {
                insertWord(words[i].substr(j),root);
            }
        }
        for(int i = 0 ; i < words.size() ; i++)
        {
            string x = "";
            for(int j = words[i].length()-1 ; j>=0 ; j--)
            {
                x+=words[i][j];
            }
            if(search(x,root))
            {
                return true;
            }
        }
        return false;
    }
};