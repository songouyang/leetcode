---
title: 303. Range Sum Query - Immutable
date: 2019-02-26 16:18:46
tags:
alias: 303/
---

对不可变数组求某个范围内的元素之和。

<!--more-->

用一个数组记录从开始到当前的所有元素之和。

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        dp = vector<int>(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }

private:
    vector<int> dp;
};
```
