---
title: 119. Pascal's Triangle II
date: 2018-12-06 11:01:18
tags:
alias: 119/
---

和 [118. Pascal's Triangle]() 相比，本题只需要输出第 `k` 行即可，但是要求空间复杂度是 `O(n)`。

同样是找规律，不断扩大下一行，因为空间复杂度的要求，所以需要用中间变量保存某些值。

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int a = 0;
        int b = 0;
        vector<int> result(1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            result.resize(i + 1);
            result[0] = result[i] = 1;
            a = result[0];
            b = result[1];
            for (int j = 1; j < i; ++j) {
                result[j] = a + b;
                a = b;
                b = result[j + 1];
            }
        }
        return result;
    }
};
```

看来评论区还有更巧妙的答案，从后往前的话，就不会覆盖二次使用的数值。

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> A(rowIndex + 1, 0);
        A[0] = 1;
        for (int i = 1; i < rowIndex + 1; i++)
            for (int j = i; j >= 1; j--)
                A[j] += A[j - 1];
        return A;
    }
};
```
