---
title: 263. Ugly Number
date: 2019-02-22 23:09:58
tags:
alias: 263/
---

求第 n 个丑数。

<!--more-->

一个丑数肯定是由 2、3 或者 5 乘以一个数字，那么认为 2、3 或者 5 投出几个数字。分别用 c2、c3 和 c5 来记录。这三个计数只能往前增加，下一个丑数就这三个投出的最小的一个数字。如果丑数是由某个数字投出，对应的计数就增加。注意 `2×3` 这种数字，它会让 2 和 3 都增加一个计数。

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result(n, 1);
        int c2 = 0, c3 = 0, c5 = 0;
        for (int i = 1; i < n; ++i) {
            result[i] = min(min(result[c2] * 2, result[c3] * 3), result[c5] * 5);
            if (result[i] == result[c2] * 2) {
                c2++;
            }
            if (result[i] == result[c3] * 3) {
                c3++;
            }
            if (result[i] == result[c5] * 5) {
                c5++;
            }
        }
        return result[n - 1];
    }
};
```

来看下这个答案，下一个丑数一定比当前的丑数大，并且由若干个 2 或 3 或 5 组成。原理和上面的是一样的。

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> uglys{1};
        static int last = 1;
        static int c2 = 2, c3 = 3, c5 = 5;
        static int i2 = 0, i3 = 0, i5 = 0;
        while (uglys.size() < n) {
            while (c2 <= last) c2 = 2 * uglys[++i2];
            while (c3 <= last) c3 = 3 * uglys[++i3];
            while (c5 <= last) c5 = 5 * uglys[++i5];
            uglys.push_back(last = min(c2, min(c3, c5)));
        }
        return uglys[n - 1];
    }
};
```
