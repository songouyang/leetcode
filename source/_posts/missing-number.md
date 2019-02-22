---
title: 268. Missing Number
date: 2019-02-22 23:26:03
tags:
alias: 268/
---

找出数组中缺少的一个数字。

<!--more-->

因为和是定值，减去数组中的总和即可。

```cpp
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};
```

用异或的方法也是可以的。
