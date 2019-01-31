---
title: 221. Maximal Square
date: 2019-01-31 22:54:50
tags:
alias: 221/
---

找出矩阵中的最大的正方形。

<!--more-->

以当前点为右下角的正方形的边，是它的上、左、左上三个点的边的最小值加上一。

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i][j])) + 1;
                    result = max(result, dp[i + 1][j + 1]);
                }
            }
        }
        return result * result;
    }
};
```
