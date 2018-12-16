---
title: 201. Bitwise AND of Numbers Range
date: 2018-12-16 23:28:57
tags:
alias: 201/
---

把一定范围内的数字全部进行 `AND` 操作，求操作后的数字。

<!--more-->

这个题目先要理解本质，就是终极操作到底为啥。先看个例子，比如 [26, 30]，这个 5 个数字的对应二进制如下：

```
11010   11011   11100   11101   11110
```

发现其实 `AND` 之后只有他们的相同左前缀了。也就是 `11000`。意思很明确了，就是区间内的数字的相同左前缀了。

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return m << i;
    }
};
```

讨论区还有其他做法。

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n &= (n - 1);
        return n;
    }
};
```

之前讨论过这个结构 `n&(n-1)`，它的作用就是去除掉 `n` 最右边的 1。

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    }
};
```

这个的话和第一个很类似了。
