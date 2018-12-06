---
title: 118. Pascal's Triangle
date: 2018-12-06 10:34:32
tags:
alias: 118/
---

杨辉三角，又叫帕斯卡三角。

<!--more-->

每个数等于它上方两数之和，然后找出二维数组中的规律即可。

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0) {
                result.push_back(vector<int>(1, 1));
            } else {
                vector<int> tmp(i + 1, 1);
                for (int j = 1; j < tmp.size() - 1; ++j) {
                    tmp[j] = result[i - 1][j - 1] + result[i - 1][j];
                }
                result.push_back(tmp);
            }
        }
        return result;
    }
};
```
