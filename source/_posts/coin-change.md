---
title: 322. Coin Change
date: 2019-03-05 14:55:18
tags:
alias: 322/
---

用最少张的钱来组成一定的金额。

<!--more-->

用动态规划即可。

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0;i<= amount;++i){
            for(auto coin: coins){
                if(i>=coin && dp[i-coin] != INT_MAX) dp[i] = min(dp[i-coin]+1, dp[i]);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
```
