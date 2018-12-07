---
title: 132. Palindrome Partitioning II
date: 2018-12-07 14:17:07
tags:
alias: 132/
---

求最少的切分次数，使得每个切分后的字段都是回文。

<!--more-->

用二维数组 `tmp` 来表示从第 `i` 到 `j` 的字符串是不是回文。用 `dp` 数组表示到某一位的最小切分次数。双重遍历，从 `j` 往前不断尝试缩小切分次数。能够切分的条件是 `i` 到 `j` 是回文，并且 `dp[i]` 可以使得 `dp[j]` 变小。

```cpp
class Solution {
public:
    int minCut(string s) {
        const auto m = s.size();
        vector<vector<bool>> tmp(m, vector<bool>(m, false));
        vector<int> dp(m, INT_MAX);
        for (int j = 0; j < m; ++j) {
            for (int i = j; i >= 0; --i) {
                if ((j - i <= 1 || tmp[i + 1][j - 1]) && s[i] == s[j]) {
                    tmp[i][j] = true;
                }
                if (tmp[i][j]) {
                    if (i == 0) {
                        dp[j] = 0;
                    } else {
                        dp[j] = min(dp[j], 1 + dp[i - 1]);
                    }
                }
            }
        }
        return dp[m - 1];
    }
};
```
