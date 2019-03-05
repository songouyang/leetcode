---
title: 326. Power of Three
date: 2019-03-05 16:39:26
tags:
alias: 326/
---

判断一个数字是不是 3 的指数。

<!--more-->

用 `3^19` 来除 `n`，如果能整除说明满足题意。因为 `3^20` 已经超过了 `int` 的范围。

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467 % n == 0;
    }
};
```
