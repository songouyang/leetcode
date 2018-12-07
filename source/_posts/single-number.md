---
title: 136. Single Number
date: 2018-12-07 16:55:22
tags:
alias: 136/
---

数组中只有一个数字出现了一次，其他数字都出现了两次，求出那个唯一的数字。

<!--more-->

这里要求不能用额外的空间，所以考虑异或操作。把数组中的所有数字异或起来。因为异或操作的顺序不影响结果，所以把两个相同的数字先异或得到 `0`。然后把所有 `0` 和那个唯一的数字异或得到结果。

```cpp
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (const auto &it:nums) {
            result ^= it;
        }
        return result;
    }
};
```

这种题如果没做过感觉很难联想到异或操作。
