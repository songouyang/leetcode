---
title: 342. Power of Four
date: 2019-03-15 13:16:17
tags:
alias: 342/
---

判断一个数字是否是 4 的指数次方。

<!--more-->

num 需要大于 0，并且用二进制表示只有 1 个 1，那么就只剩下 2 的指数次方和 4 的指数次方。
4^n % 3 等于 (4%3)^n % 3 等于 1。而假设 n 是奇数，那么 2^n 等于 2^(n-1) * 2，前者的余数为 1，后者的余数为 2。

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num - 1) % 3 == 0);
    }
};
```
