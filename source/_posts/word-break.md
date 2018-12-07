---
title: 139. Word Break
date: 2018-12-07 20:37:25
tags:
alias: 139/
---

判断一个单词是不是可以从单词列表中的单词组成。

<!--more-->

这个题目之前的 [132. Palindrome Partitioning II](/palindrome-partitioning-ii/) 很类似。只是需要注意的话，如果找到 `dp[i]` 等于 `true` 的时候跳出循环，因为只要求证能否分割开来。

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        const auto n = s.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] && dict.find(s.substr(j, i - j + 1)) != dict.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```
