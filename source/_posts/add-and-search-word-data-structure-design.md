---
title: 211. Add and Search Word - Data structure design
date: 2018-12-24 19:47:38
tags:
alias: 211/
---

添加和搜索单词。

<!--more-->

把之前的 `Trie` 树 [208. Implement Trie (Prefix Tree)](https://songouyang.github.io/leetcode/implement-trie-prefix-tree/) 稍微改一下即可。

```cpp
class TrieNode {
public:
    bool isWord = false;
    char val;
    unordered_map<char, TrieNode *> child;

    TrieNode(char c) {
        val = c;
    };
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode('#');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = root;
        for (const auto &it: word) {
            if (!curr->child.count(it)) {
                curr->child[it] = new TrieNode(it);
            }
            curr = curr->child[it];
        }
        curr->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode *curr = root;
        return helper(word, curr);
    }

private:
    TrieNode *root;

    bool helper(string word, TrieNode *curr) {
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] != '.') {
                if (curr->child.count(word[i])) {
                    curr = curr->child[word[i]];
                } else {
                    return false;
                }
            } else {
                for (const auto &it : curr->child) {
                    if (helper(word.substr(i + 1), it.second)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return curr->isWord;
    }
};
```
