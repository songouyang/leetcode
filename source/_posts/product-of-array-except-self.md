---
title: 238. Product of Array Except Self
date: 2019-02-20 20:34:26
tags:
alias: 238/
---

数组内除去当前 `index` 的数字的其他数字的乘积，要求不能用除法。

<!--more-->

用两个变量分别记录从左往右和从右往左的累乘。

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size(), left = 1, right = 1;
        vector<int> result(n, 1);
        for (int i = 0; i < n; ++i) {
            result[i] *= left;
            left *= nums[i];
            result[n - 1 - i] *= right;
            right *= nums[n - 1 - i];
        }
        return result;
    }
};
```

还有一种解法使用 `DFS` 的入栈与出栈来实现左右两边累计乘法计数。看起来还挺巧的方法。

```cpp
class Solution {
public:
    Solution() {
        right = 1;
    }

    vector<int> productExceptSelf(vector<int> &nums) {
        dfs(nums, 1, 0);
        return nums;
    }

    void dfs(vector<int> &nums,
             int left,
             int index) {
        if (index == nums.size()) {
            return;
        }
        dfs(nums, left * nums[index], index + 1);
        int tmp = nums[index];
        nums[index] = left * right;
        right = right * tmp;
    }

private:
    int right;
};
```
