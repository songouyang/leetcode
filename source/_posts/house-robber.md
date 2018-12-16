---
title: 198. House Robber
date: 2018-12-16 20:08:46
tags:
alias: 198/
---

如何抢劫可以获利最高。

<!--more-->

要求不能抢劫相邻的两个店铺。

```cpp
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        const auto n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};
```
