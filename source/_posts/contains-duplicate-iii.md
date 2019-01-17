---
title: 220. Contains Duplicate III
date: 2019-01-17 19:43:30
tags:
alias: 220/
---

在数组中能否找出这样两个数字，保证下标的绝对值不大于 `k`，同时两个数字的绝对值不大于 `t`。

<!--more-->

使用 `lower_bound` 在有序容器中找出第一个不小于 `nums[i] - t` 的数字的下表（其实是迭代器）。这保证了找出来的数字 `x` 大于等于 `nums[i] - t`；同时下面保证了 `x - nums[i]` 是小于等于 `t` 的。所以得到：`x-nums[i]` 的绝对值小于等于 `t`。

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) s.erase(nums[i - k - 1]);
            auto p = s.lower_bound((long) nums[i] - t);
            if (p != s.end() && (*p - nums[i]) <= t) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
```
