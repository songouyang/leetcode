---
title: 115. Distinct Subsequences
date: 2018-12-05 21:33:18
tags:
alias: 115/
---

单词 `t` 是从 `s` 中按照从左往右的顺序取出若干的单词拼接而成，问有多少种这样的取法。

<!--more-->

用二维的动态规划。首先先找到递归关系式，举个例子：`s` 是 `babgbag` 而 `t` 是 `bag`，因为尾部都是 `g`。所以它的数量应该等于 `babgba` 与 `ba` 的数量加上 `babgba` 与 `bag` 的数量之和。如果尾部不相等，举个例子 `s` 是 `babgbag` 而 `t` 是 `ba`，那么它的数量应该等于 `babgba` 与 `ba` 的数量。

初始化二维矩阵的话，直接举个例子就得到第一行应该是 `1`，而第一列应该是 `0`。

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.length();
        const int n = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
```

一般如果二维动态规划需要优化空间的话，可以通过添加一个或几个中间变量，使得空间复杂度变成 `O(n)`。
