---
title: 191. Number of 1 Bits
date: 2018-12-16 17:48:17
tags:
alias: 191/
---

计算一个数字有多少个比特位是 `1` 的。

<!--more-->

这个《编程之美》有类似的题目。`n-1` 就是把 `n` 最右边的一个 `1` 去掉。`n&(n-1)` 就会把最右边的一个 `1` 抹除掉。
举个例子：`n` 等于 `0b10100`，则 `n-1` 等于 `0b10011`，那么 `n&(n-1)` 等于 `0b10000`。

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            result += 1;
            n = n & (n - 1);
        }
        return result;
    }
};
```
