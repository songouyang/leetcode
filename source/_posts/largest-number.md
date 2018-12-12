---
title: 179. Largest Number
date: 2018-12-12 16:27:41
tags:
alias: 179/
---

使得数组中的数字拼起来后的数字最大。

<!--more-->

对于 `i` 和 `j` 两个数字，如果 `str(i)+str(j)` 比 `str(j)+str(i)` 大的话，那么 `i` 应该排在 `j` 前面。

```cpp
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(),
             [](int i, int j) { return to_string(i) + to_string(j) > to_string(j) + to_string(i); });
        string result;
        if (nums[0] == 0)return "0";
        for (const auto &num:nums) {
            result += to_string(num);
        }
        return result;
    }
};
```
