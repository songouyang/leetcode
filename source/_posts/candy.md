---
title: 135. Candy
date: 2018-12-07 16:44:46
tags:
alias: 135/
---

保证每个孩子至少有一个糖，如果比相邻的孩子的分数高，那么糖的个数也要比那个邻居更多。

<!--more-->

分成左右两次遍历，第一次遍历保证如果比左边的孩子分数更高，那么糖更多。第二次遍历，如果分数比右边的孩子更高，并且糖更少，那么把他的糖设置为比右边孩子的糖多一个。最后把所有糖加起来就好了。

```cpp
class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        vector<int> tmp(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                tmp[i] = tmp[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && tmp[i] <= tmp[i + 1]) {
                tmp[i] = tmp[i + 1] + 1;
            }
        }
        int result = 0;
        for (const auto &it: tmp) {
            result += it;
        }
        return result;
    }
};
```
