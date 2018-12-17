---
title: 208. Implement Trie (Prefix Tree)
date: 2018-12-17 20:53:28
tags:
alias: 208/
---

实现字典树的插入和查询。

<!--more-->

我这里用 `map` 来记录子节点，用字符就可以查询到对应的节点。

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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('#');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (const auto &it: word) {
            if (!curr->child.count(it)) {
                curr->child[it] = new TrieNode(it);
            }
            curr = curr->child[it];
        }
        curr->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for (const auto &it : word) {
            if (curr->child.count(it)) {
                curr = curr->child[it];
            } else {
                return false;
            }
        }
        return curr->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (const auto &it: prefix) {
            if (curr->child.count(it)) {
                curr = curr->child[it];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode *root;
};
```
