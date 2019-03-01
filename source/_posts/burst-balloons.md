---
title: 312. Burst Balloons
date: 2019-03-01 18:30:38
tags:
alias: 312/
---

如何涂气球可以获得最多的金币。

<!--more-->

关键是切分成字问题。假设中间的气球 `i` 是最后涂的一个气球，那么它左右两边始终都不会相互影响。
对于左右边界分别是 `left` 和 `right` 的区间，通过 `i` 来切分。那么最优解是左边的最大，右边的最大，以及最左和最优的相乘。注意就是求左边的时候，是不会把最左这个值加进去，它是开区间，所以最后把左右边界乘以 `inums[i` 加上去。

```cpp
class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size() + 2;
        vector<int> inums(n, 1);
        for (int i = 0; i < n - 2; ++i) {
            inums[i + 1] = nums[i];
        }
        int dp[n][n];
        for (int k = 2; k < n; ++k) {
            for (int left = 0; left + k < n; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(dp[left][right],
                                          dp[left][i] + dp[i][right] + inums[left] * inums[i] * inums[right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
```
