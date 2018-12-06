---
title: 120. Triangle
date: 2018-12-06 11:47:24
tags:
alias: 120/
---

从一个二维数组的顶到底部，所经过的路径的数字之和最小。

<!--more-->

这是动态规划的题目，下一层的某个点的最小值应该是上方两个数值的最小值加上本身的数值。为了方便计算，我在 `dp` 数组左侧多加了个 `INT_MAX`，这样省去了判断边缘。然后遍历每一层的时候也是从右往左，防止覆盖需要二次使用的数值。

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        const int m = triangle.size();
        vector<int> dp(m + 1, INT_MAX);
        dp[1] = triangle[0][0];
        for (int i = 1; i < m; ++i) {
            for (int j = i; j >= 0; --j) {
                dp[j + 1] = std::min(dp[j + 1], dp[j]) + triangle[i][j];
            }
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};
```

我的答案的空间复杂是 `O(n)`，还有空间复杂度是 `O(1)` 的，它就是利用本身的 `triangle` 数组的空间，从底部往上游走计算。

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int row = triangle.size();
        for (int i = row - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
        return triangle[0][0];
    }
};
```
