// time complexity for insert and search is O(N)

#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode **children;
    bool isEndOfWord;
};

struct Trie{

    int ALPHABET_SIZE;
    TrieNode* root;

    Trie(int n){
        ALPHABET_SIZE = n;
        root = getTrieNode();
    }

    TrieNode* getTrieNode(){
        TrieNode* node = new TrieNode;
        node->isEndOfWord = false;
        node->children = new TrieNode*[ALPHABET_SIZE];
        for(int i = 0; i < ALPHABET_SIZE; i++)  node->children[i] = NULL;
        return node;
    }

    void insert(string str){
        TrieNode *pCrawl = root;
        for (int i = 0; i < str.length(); i++){
            int ch = str[i] - 'a';
            if (!pCrawl->children[ch])  pCrawl->children[ch] = getTrieNode();
            pCrawl = pCrawl->children[ch];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(string str){
        TrieNode *pCrawl = root;
        for (int i = 0; i < str.length(); i++){
            int ch = str[i] - 'a';
            if (!pCrawl->children[ch])  return false;
            pCrawl = pCrawl->children[ch];
        }
        return (pCrawl != NULL && pCrawl->isEndOfWord);
    }
};

int main(){


    Trie trie(26);

    // insert some keys
    string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    for (int i = 0; i < n; i++)
        trie.insert(keys[i]);

    // Search for different keys
    string search_key;
    while(cin>>search_key){
        trie.search(search_key)? cout << "Yes\n" :cout << "No\n";
    }

    return 0;

}
