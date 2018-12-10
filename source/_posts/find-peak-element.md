---
title: 162. Find Peak Element
date: 2018-12-10 14:45:54
tags:
alias: 162/
---

找出数组中的其中一个峰。

<!--more-->

因为只需要找出一个，所以采用二分搜索很好做。题目的条件是相邻的两个数字不会相等，那么我取两个中间值，查看它们的变化趋势。如果 `nums[mid1] < nums[mid2]` 说明是上升的，那么右边肯定有一个峰。否则就是左边肯定有一个峰。

```cpp
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(const vector<int> &nums, int i, int j) {
        if (i == j) {
            return i;
        }
        int mid1 = (i + j) / 2;
        int mid2 = mid1 + 1;
        if (nums[mid2] > nums[mid1]) {
            return helper(nums, mid2, j);
        } else {
            return helper(nums, i, mid1);
        }
    }
};
```
