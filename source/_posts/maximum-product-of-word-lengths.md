---
title: 318. Maximum Product of Word Lengths
date: 2019-03-04 15:46:00
tags:
alias: 318/
---

给定一些字符串，求两个没有交集的字符串长度的乘积最大值。

<!--more-->

用位运算来求两个字符串有没有交集。

```cpp
class Solution {
public:
    int maxProduct(vector<string> &words) {
        int n = words.size();
        int result = 0;
        vector<int> tmp(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                tmp[i] |= 1 << (words[i][j] - 'a');
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((tmp[i] & tmp[j]) == 0) {
                    result = max(result, (int) (words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
};
```
