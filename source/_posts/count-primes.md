---
title: 204. Count Primes
date: 2018-12-17 11:14:43
tags:
alias: 204/
---

计算 n 以内的素数。

<!--more-->

直接逐一判断的话耗时很长，看了一下别人的做法，采用了 [厄拉多塞筛法](https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95) 利用空间换时间。也就是当判断到 2 的时候，就会把 2 的倍数都设置成不是素数。类似的 3 的倍数，5 的倍数等等。

```cpp
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> check(n, true);
        int result = 0;
        for (int i = 2; i < n; ++i) {
            if (check[i]) {
                ++result;
                for (int j = 2; i * j < n; ++j) {
                    check[i * j] = false;
                }
            }
        }
        return result;
    }
};
```
