---
title: 330. Patching Array
date: 2019-03-07 15:47:20
tags:
alias: 330/
---

题目提供了一个数组，需要你补充一些数字，使得这些元素可以拼接 1 到 n 的值。

<!--more-->

首先从 1 开始补。如果已经补充到 n1 了，如果下一个数组中的数字大于 n1 + 1，那么就需要补充 n1 + 1 了。如果小于的话，那就利用本有的数字 m1，那么现在最大的范围就是 n1+m1 了。然后就是下一个值就是 n1+m1+1 了，以此类推。

```cpp
class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int count = 0, i = 0;
        long long num = 0;
        while (num < n) {
            if (i < nums.size() && nums[i] <= num + 1) {
                num += nums[i++];
            } else {
                num += num + 1;
                ++count;
            }
        }
        return count;
    }
};
```
