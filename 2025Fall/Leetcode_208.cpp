// Leetcode 208: Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
using namespace std;

// 1. Tree with 26 branches
struct TrieNode {
    bool end;
    TrieNode *next[26];
    TrieNode() {
        end = false;
        for(int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }       
    }
};

class Trie {
public:
    TrieNode* ns;
    Trie() {
        ns = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = ns;
        int k = 0;
        for(char c : word) {
            k = c - 'a';
            if(tmp->next[k] == nullptr) {
                tmp->next[k] = new TrieNode();
            }
            tmp = tmp->next[k];
        }
        tmp->end = true;
    }
    
    bool search(string word) {
        TrieNode* tmp = ns;
        int k = 0;
        for(char c : word) {
            k = c - 'a';
            if(tmp->next[k] == nullptr) {
                return false;
            }
            tmp = tmp->next[k];
        }
        if(tmp->end == 0) {
            return false;
        } else {
            return true;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = ns;
        int k = 0;
        for(char c : prefix) {
            k = c - 'a';
            if(tmp->next[k] == nullptr) {
                return false;
            }
            tmp = tmp->next[k];
        }    
        return true;    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */