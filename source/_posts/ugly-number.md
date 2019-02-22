---
title: 263. Ugly Number
date: 2019-02-22 16:53:13
tags:
alias: 263/
---

如果一个数字可以由 2、3、5 乘积而成，则称为丑数。判断一个数字是否为丑数。

<!--more-->

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        if (num % 2 == 0) {
            num /= 2;
            return isUgly(num);
        } else if (num % 3 == 0) {
            num /= 3;
            return isUgly(num);
        } else if (num % 5 == 0) {
            num /= 5;
            return isUgly(num);
        }
        return num == 1;
    }
};
```
