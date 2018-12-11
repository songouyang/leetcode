---
title: 168. Excel Sheet Column Title
date: 2018-12-11 12:28:33
tags:
alias: 168/
---

将数字转化为 Excel 中的头的形式。

<!--more-->

不断对 26 取整和取余即可。

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        if (n == 0)return result;
        result += (char) ('A' + (--n % 26));
        return convertToTitle(n / 26) + result;
    }
};
```

需要注意的地方是取余数的时候，需要先减去 1，再取余数，因为这样加上 A 才是想要的结果。而且减去 1 再取整也才是对的，因为它表面上到 27 才进位。
