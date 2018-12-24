---
title: 213. House Robber II
date: 2018-12-24 21:14:23
tags:
alias: 213/
---

假设抢劫的街道上是环，并且不能抢劫相邻的两个。

<!--more-->

在第一个的基础上稍微改动一下即可，要么去掉头，要么去掉尾就可以保证头尾不会相邻抢劫。

```cpp
class Solution {
public:
    int rob(vector<int> &nums) {
        auto const n = nums.size();
        if (n == 1) return nums[0];
        if (n == 0) return 0;
        vector<int> tmp1(nums.begin() + 1, nums.end());
        int a = helper(tmp1);
        vector<int> tmp2(nums.begin(), nums.end() - 1);
        int b = helper(tmp2);
        return max(a, b);
    }

private:
    int helper(vector<int> &nums) {
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
