---
title: 174. Dungeon Game
date: 2018-12-11 20:17:11
tags:
alias: 174/
---

最小的出发血量可以战斗到最后。

<!--more-->

这个动态规划需要逆着来，首先它到达右下角的前的最低血量应该是 `max(1, -dungeon[m - 1][n - 1] + 1)`，也就是如果最后一个格子是负数的话，应该保证这个数字加上那个负数后也应该等于 1，如果最后一个是正数的话，那么等于 1，就可以保证勇士不会死了。
递推关系和上面的分析类似。

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        const auto m = dungeon.size();
        const auto n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = max(1, -dungeon[m - 1][n - 1] + 1);
        for (int i = m - 2; i >= 0; --i) {
            dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
        }
        for (int i = n - 2; i >= 0; --i) {
            dp[m - 1][i] = max(dp[m - 1][i + 1] - dungeon[m - 1][i], 1);
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
```
