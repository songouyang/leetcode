---
title: 336. Palindrome Pairs
date: 2019-03-15 11:27:55
tags:
alias: 336/
---

找出所有俩俩组成回文的字符串。

<!--more-->

这个题目花了很长时间理解。

首先是采用 Trie 树的方法，把单词反过来建树，然后搜索。这个解法不能通过，因为会 `Memory Limit Exceeded`。

```cpp
class TrieNode {
public:
    int idx;
    vector<int> indices;
    vector<TrieNode *> children;

    TrieNode() {
        idx = -1;
        children = vector<TrieNode *>(26, nullptr);
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            add(words[i], i);
        }
        for (int i = 0; i < words.size(); ++i) {
            search(words[i], i, result);
        }
        return result;
    }

private:
    TrieNode *root = new TrieNode();

    void add(string word, int i) {
        TrieNode *node = root;
        for (int j = (int) word.size() - 1; j >= 0; --j) {
            if (isValid(word, 0, j)) node->indices.push_back(i);
            if (!node->children[word[j] - 'a']) {
                node->children[word[j] - 'a'] = new TrieNode();
            }
            node = node->children[word[j] - 'a'];
        }
        node->idx = i;
        node->indices.push_back(i);
    };

    void search(string word, int i, vector<vector<int>> &result) {
        TrieNode *node = root;
        int n = (int) word.size();
        for (int j = 0; j < n && node; ++j) {
            if (node->idx >= 0 && isValid(word, j, n - 1)) {
                result.push_back({i, node->idx});
            }
            node = node->children[word[j] - 'a'];
        }
        if (node) {
            for (auto it: node->indices) {
                if (it != i) {
                    result.push_back({i, it});
                }
            }
        }
    };

    bool isValid(string word, int i, int j) {
        while (i < j) {
            if (word[i++] != word[j--]) return false;
        }
        return true;
    }
};
```

然后是采用 map 和 set 来实现的。用 map 记录字符串到下标的映射。用 set 记录所有单词的长度。然后将单词反转，判断是否存在。接下来从比该单词更短的单词中找到，它要求多余出来的那部分已经是个回文了。

```cpp
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> result;
        unordered_map<string, int> umap;
        set<int> s;
        for (int i = 0; i < words.size(); ++i) {
            umap[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); ++i) {
            string tmp = words[i];
            int len = (int) tmp.size();
            reverse(tmp.begin(), tmp.end());
            if (umap.count(tmp) && umap[tmp] != i) {
                result.push_back({i, umap[tmp]});
            }
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                if (isValid(tmp, 0, len - d - 1) && umap.count(tmp.substr(len - d))) {
                    result.push_back({i, umap[tmp.substr(len - d)]});
                }
                if (isValid(tmp, d, len - 1) && umap.count(tmp.substr(0, d))) {
                    result.push_back({umap[tmp.substr(0, d)], i});
                }
            }
        }
        return result;
    }

private:
    bool isValid(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
```
