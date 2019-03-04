---
title: 319. Bulb Switcher
date: 2019-03-04 16:00:17
tags:
alias: 319/
---

求 n 轮开关之后，还有多少个灯泡是关的。

<!--more-->

可以发现，第 3 个灯泡会在 1、3 轮被开关，第 4 个灯泡会在 1、2、4 轮被开关。比如 6 可以被拆成 1、6、2、3。所以它的因子都是成对的，但是如果是平方数比如 4 就是不是成对的。所以只需要求出往下有多少个平方数即可。

```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
```
