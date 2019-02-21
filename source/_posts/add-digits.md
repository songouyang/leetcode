---
title: 258. Add Digits
date: 2019-02-21 11:29:06
tags:
alias: 258/
---

给定一个数字，求出各个位置加起来的和。如果和的位数大于 1，那么继续递归。

<!--more-->

我按照题意直接写的。

```cpp
class Solution {
public:
    int addDigits(int num) {
        if (num / 10 == 0) return num;
        int result = 0;
        while (num != 0) {
            result += num % 10;
            num /= 10;
        }
        return addDigits(result);
    }
};
```

分享一下啊别人的，假设一个数字是三位数，表示成 `100a+10b+c`，对 9 取余数就可以得到 `a+b+c` 了。一步到位，厉害了。

```cpp
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        int s = num % 9;
        if (s == 0) {
            return 9;
        } else return s;
    }
};
```
