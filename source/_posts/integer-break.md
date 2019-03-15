---
title: 343. Integer Break
date: 2019-03-15 13:48:30
tags:
alias: 343/
---

给定一个整数 n，将 n 分成至少两个整数，使得分成后的整数之积最大。

<!--more-->

只要 n 大于 4，它可以对半分，然后乘积会更大。当它等于 4，那么拆不拆都是一样。小于 4 就直接特例判断。
那么一直对半分要么是回落到 1、2、3 三者之一。优先使用 3，因为通过 6 的例子，知道 3 会使得结果更大。

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int result = 1;
        while (n > 4) {
            result *= 3;
            n -= 3;
        }
        return result * n;
    }
};
```
