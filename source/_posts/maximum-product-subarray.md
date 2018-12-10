---
title: 152. Maximum Product Subarray
date: 2018-12-10 11:23:00
tags:
alias: 152/
---

求连续子序列的乘积最大。

<!--more-->

因为涉及到负数，所以需要保持一个局部最小和一个局部最大。如果局部最小乘以负数可能变成最大，同理局部最大乘以负数可能变成最小。因此递推比较的时候，需要把三个值都拿出来比较。

```cpp
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int local_min = nums[0];
        int local_max = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int t_min = nums[i] * local_min;
            int t_max = nums[i] * local_max;
            local_min = min(min(t_min, nums[i]), t_max);
            local_max = max(max(t_max, nums[i]), t_min);
            result = max(result, local_max);
        }
        return result;
    }
};
```
