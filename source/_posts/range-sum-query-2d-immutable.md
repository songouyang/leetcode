---
title: 304. Range Sum Query 2D - Immutable
date: 2019-02-26 16:48:47
tags:
alias: 304/
---

对不可变二维数组求某个范围内的元素之和。

<!--more-->

用一个二维数组记录从开始到当前的所有元素之和。

```cpp
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                count += matrix[i][j];
                dp[i + 1][j + 1] = dp[i][j + 1] + count;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }

private:
    vector<vector<int>> dp;
};
```
