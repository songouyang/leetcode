---
title: 172. Factorial Trailing Zeroes
date: 2018-12-11 15:09:02
tags:
alias: 172/
---

求 n 的阶乘后面的 0 的个数。

<!--more-->

因为 0 是由 2 和 5 相乘得到，并且 2 的个数远比 5 的个数多，所以其实只需要计算 5 的个数。
把 n 的阶乘先看成 1 * 2 * …… * n，在这些数字中能被 5 整除的数字的个数是 `n/5`。能被 25 整除的个数是 `n/25`，被 25 整除的数字应该贡献了两个 5。同理能被 125 整除的数字贡献了 3 个数字。

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        return n < 5 ? 0 : trailingZeroes(n / 5) + n / 5;
    }
};
```
