---
title: 233. Number of Digit One
date: 2019-02-20 17:18:54
tags:
alias: 233/
---

找出从 1 到 n 中用十进制表示的话包含多少个 1。

<!--more-->

这里主要是找规律。
1. 首先如果不考虑特殊的数字，应该是每十个数字出现一个 1。
2. 还有一个特殊组那就是 `[11, 19]`、`[111, 119]` 这种。如果正好落入这个组内，拿 12 举个例子，它多出来了的 1 应该是 10，11，12。所以需要加上 `(r % 10 == 1 ? m + 1 : 0)`。
3. 还有一个特殊就是如果把上一步的一组都包含进来了，那就要多加上一个对应等级的组的 1 的个数。比如 21，那么它本来应该包含两位数字的等级。但是它的十位数大于等于 2，所以还需要加上一个三位数字的等级。

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        int result = 0;
        for (long long k = 1; k <= n; k *= 10) {
            long long r = n / k, m = n % k;
            result += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
        return result;
    }
};
```

参考链接🔗：<https://leetcode.com/problems/number-of-digit-one/discuss/64390/AC-short-Java-solution>
