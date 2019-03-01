---
title: 313. Super Ugly Number
date: 2019-03-01 20:10:00
tags:
alias: 313/
---

给定质数集合，求出第 n 小的丑数。

<!--more-->

和 [263. Ugly Number](https://songouyang.github.io/leetcode/ugly-number-ii/) 是一样的原理，只是之前只有 2、3、5，现在是一个集合。

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;
        vector<int> idx(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes.size(); ++j) {
                dp[i] = min(dp[i], primes[j] * dp[idx[j]]);
            }
            for (int j = 0; j < primes.size(); ++j) {
                if (dp[i] == primes[j] * dp[idx[j]]) {
                    idx[j]++;
                }
            }
        }
        return dp.back();
    }
};
```
