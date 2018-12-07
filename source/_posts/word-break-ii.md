---
title: 140. Word Break II
date: 2018-12-07 21:32:32
tags:
alias: 140/
---

对一个字符串按照字典里存在的单词进行切分，并且把切分后的单词用空格连起来。

<!--more-->

用一个 `map` 记住从 `s` 到可切分的数组，防止重复切分。然后就是 DFS 回溯切分一下。

```cpp
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set <string> dict(wordDict.begin(), wordDict.end());
        return helper(s, dict);
    }

    vector<string> helper(string s, unordered_set <string> &dict) {
        if (mp.count(s)) {
            return mp[s];
        }
        vector<string> result;
        for (int i = 0; i < s.size(); ++i) {
            string word = s.substr(i);
            if (dict.count(word)) {
                if (i == 0) {
                    result.push_back(word);
                } else {
                    for (auto &it: helper(s.substr(0, i), dict)) {
                        result.push_back(it + " " + word);
                    }
                }
            }
        }
        mp[s] = result;
        return result;
    }

private:
    unordered_map<string, vector<string>> mp;
};
```
