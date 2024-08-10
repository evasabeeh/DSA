#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];                 // no. suffices ahead of that node

    TrieNode(char c){
        data=c;                             // node value
        isTerminal=false;                   // if the node is the last node
        for(int i=0;i<26;i++)
        children[i]=nullptr;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');          // root node started with null char
    }
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0)                // word is inserted
        root->isTerminal=true;

        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != nullptr)      // the char is already there
        child=root->children[idx];
        else{
            child = new TrieNode(word[0]);      // if not there
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));      // one by one char is inserted
    }
    void insertWord(string word){
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0)
        return root->isTerminal;       // if the last node will not be terminal, then it will return false, though the word is present

        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != nullptr)
        child = root->children[idx];
        else
        return false;

        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root, word);
    }
};
int main(){
    Trie *t = new Trie();
    t->insertWord("and");
    t->insertWord("ant");
    t->insertWord("bed");
    t->insertWord("red");
    cout<<t->searchWord("ant");
    cout << t->searchWord("be");

    return 0;
}

// to remove a word, you have to search the word and then make the terminal as non-terminal node, and then you need to optimize the space



// insertion: O(length of word)
// search: O(length of word)
// removal: O(length of word)