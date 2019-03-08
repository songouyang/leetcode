---
title: 334. Increasing Triplet Subsequence
date: 2019-03-08 15:34:18
tags:
alias: 334/
---

判断一个数组中是否存在三个递增的序列，可以不连续。

<!--more-->

用 a1 和 a2 来记录目前遇到的最小的和倒数第二小的，如果遇到第三个，那么就说明存在了。

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int a1 = INT_MAX, a2 = INT_MAX;
        for (auto num: nums) {
            if (num <= a1) {
                a1 = num;
            } else if (num <= a2) {
                a2 = num;
            } else {
                return true;
            }
        }
        return false;
    }
};
```
