---
title: 240. Search a 2D Matrix II
date: 2019-02-20 23:33:14
tags:
alias: 240/
---

在一个二维数组中判断一个数字是否存在。

<!--more-->

利用二维数组已经存在的特性，从某一个角开始搜索。通过比较大小判断是走上下还是左右。

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while (i < m && j > -1) {
            int num = matrix[i][j];
            if (target == num) {
                return true;
            } else if (target > num) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};
```
