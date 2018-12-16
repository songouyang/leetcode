---
title: 200. Number of Islands
date: 2018-12-16 20:47:19
tags:
alias: 200/
---

找出有多少个孤立的小岛。

<!--more-->

用 DFS 遍历一次，把走过的地方都改成 `0`。

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    helper(grid, i, j);
                    ++result;
                }

            }
        }
        return result;
    }

    void helper(vector<vector<char>> &grid, int i, int j) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1') {
            grid[i][j] = '0';
            helper(grid, i + 1, j);
            helper(grid, i - 1, j);
            helper(grid, i, j + 1);
            helper(grid, i, j - 1);
        }
    }
};
```
