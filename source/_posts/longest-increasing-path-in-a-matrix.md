---
title: 329. Longest Increasing Path in a Matrix
date: 2019-03-07 15:45:14
tags:
alias: 329/
---

寻找二为矩阵中最长的递增路径。

<!--more-->

这个和之前的在二为矩阵中找字符串很类似，都是用 DFS，但是这里稍微有点不同的是，为了减少重复计算，降低运算时间，需用用 DP 缓存已经计算过的节点。

```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int result = 0;
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = helper(matrix, i, j, m, n, dp);
                result = max(result, tmp);
            }
        }
        return result;
    }

private:
    vector<vector<int>> dirs = {{1,  0},
                                {-1, 0},
                                {0,  1},
                                {0,  -1}};

    int helper(vector<vector<int>> &matrix, int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (dp[i][j]) return dp[i][j];
        int tmp = 1;
        for (auto dir: dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + helper(matrix, x, y, m, n, dp);
            tmp = max(tmp, len);
        }
        dp[i][j] = tmp;
        return tmp;
    }
};
```
