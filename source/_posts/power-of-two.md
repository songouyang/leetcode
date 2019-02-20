---
title: 231. Power of Two
date: 2019-02-20 17:08:20
tags:
alias: 231/
---

判断一个数字是否为 2 的指数次方。

<!--more-->

一个数字是 2 的指数次方的数字用二进制表示的话，只能包含一个 1。

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        int c = 0;
        for (; n; ++c) {
            n = n & (n - 1);
        }
        return c == 1;
    }
};
```

`n & (n - 1)` 是用来去除二进制中最右边的一个 1，我把 1 的个数记录下来，然后判断是否为一个。

评论区的朋友写的比我好。

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        return !n & (n - 1);
    }
};
```
