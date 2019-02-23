---
title: 279. Perfect Squares
date: 2019-02-23 20:31:05
tags:
alias: 279/
---

给定一个数字 n，求最少由多少个平方数组成。

<!--more-->

用动态规划的方法即可。

```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
```
