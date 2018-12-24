---
title: 212. Word Search II
date: 2018-12-24 21:00:02
tags:
alias: 212/
---

在二维矩阵中搜索多个单词。

<!--more-->

和之前搜索一个单词不同，这里需要考虑优化搜索前缀相同的单词。所有先使用 `Trie` 树把所有单词存起来。然后在 DFS 的过程如果发现找到了其中的一个单词，就把单词加入结果中。

```cpp
class TrieNode {
public:
    string word = "";
    vector<TrieNode *> next{26, nullptr};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> result;
        TrieNode *root = build(words);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                helper(board, i, j, result, root);
            }
        }
        return result;
    }

private:
    void helper(vector<vector<char>> &board, int i, int j, vector<string> &result, TrieNode *root) {
        char c = board[i][j];
        if (c == '#' || root->next[c - 'a'] == nullptr) {
            return;
        }
        root = root->next[c - 'a'];
        if (!root->word.empty()) {
            result.push_back(root->word);
            root->word = "";
        }
        board[i][j] = '#';
        if (i > 0) helper(board, i - 1, j, result, root);
        if (j > 0) helper(board, i, j - 1, result, root);
        if (i < board.size() - 1) helper(board, i + 1, j, result, root);
        if (j < board[0].size() - 1) helper(board, i, j + 1, result, root);
        board[i][j] = c;
    }

    TrieNode *build(const vector<string> &words) {
        auto root = new TrieNode();
        for (const auto &word: words) {
            auto tmp = root;
            for (const auto &it : word) {
                int t = it - 'a';
                if (tmp->next[t] == nullptr) {
                    tmp->next[t] = new TrieNode();
                }
                tmp = tmp->next[t];
            }
            tmp->word = word;
        }
        return root;
    }
};
```
