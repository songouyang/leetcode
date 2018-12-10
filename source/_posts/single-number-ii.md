---
title: 137. Single Number II
date: 2018-12-07 19:34:18
tags:
alias: 137/
---

和 [136. Single Number](https://songouyang.github.io/leetcode/single-number/) 不同的地方是这里的次数变成了 3 次。

<!--more-->

需要用位图的思想来考虑。假设考虑某一个比特，`one` 等于 1 代表这个比特来了一个 1，`two` 等于 1 代表这个比特来了两个 1，`three` 等于 1 代表这个比特来了三个 1。来更多 1 的时候要形成循环，也就是来了第四个 1 的时候，应该是 `one` 上的比特等于 1，而 `two` 和 `three` 应该等于 0。

```cpp
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int one(0), two(0), three(0);
        for (const auto &it: nums) {
            two |= one & it;
            one ^= it;
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};
```

还有一个更巧妙的方法。它利用了三进制。这个三进制由两个比特组成，叫做 `ab`。`ab` 的初始条件是 `00`，状态的变化为 `00->01->10->00`。所以最后多出来的一个数字正好可以由 `b` 来表示了！

```cpp
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int a(0), b(0);
        for (const auto &it: nums) {
            b = (b ^ it) & ~a;
            a = (a ^ it) & ~b;
        }
        return b;
    }
};
```
