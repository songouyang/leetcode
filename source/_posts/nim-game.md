---
title: 292. Nim Game
date: 2019-02-25 14:32:25
tags:
alias: 292/
---

谁取到最后一个石头就会获胜。判断石头的总数是多少的时候，你是否一定能获胜。

<!--more-->

只要 n 不能被 4 整除，你都可以拿到最后一个石头。比如 n = 4a + b。你第一次拿 b 个石头，然后它拿 x 个，你就拿 4-x 个即可。

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```
