---
title: 223. Rectangle Area
date: 2019-02-05 22:38:47
tags:
alias: 223/
---

给定 4 个点，求出这两个长方形的面积。

<!--more-->

首先假如两个长方形不相交，那么结果就是两个长方形面积相加。如果两个长方形相交，那么需要减去相交的长方形的面积。

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (A - C) * (B - D) + (E - G) * (F - H);
        if (C <= E || G <= A || H <= B || D <= F) {
            return result;
        }
        int w = min(C, G) - max(A, E);
        int h = min(D, H) - max(B, F);
        return result - w * h;
    }
};
```
