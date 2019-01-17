---
title: 219. Contains Duplicate II
date: 2019-01-17 13:32:04
tags:
alias: 219/
---

找出数组中相同的两个数字，并且他两的下标的绝对值不超过 `k`。

<!--more-->

使用 `set` 记录往前 `k` 个数字，并且不断新增当前的数字，和删除第前 `k` 个数字。

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
```
