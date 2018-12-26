---
title: 215. Kth Largest Element in an Array
date: 2018-12-26 15:13:43
tags:
alias: 215/
---

无序数组中第 K 大的数字。

<!--more-->

采用分治的思想。找到第 K 大的数字在哪一边。

```cpp
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return helper(nums, k, 0, nums.size() - 1);
    }

private:
    int helper(vector<int> &nums, int k, int left, int right) {
        int l = left, r = right;
        int p = nums[l];
        while (l < r) {
            while (l < r && p >= nums[r]) {
                --r;
            }
            nums[l] = nums[r];
            if (l < r) ++l;
            while (l < r && p <= nums[l]) {
                ++l;
            }
            nums[r] = nums[l];
            if (l < r) --r;
        }
        nums[l] = p;
        if (l + 1 == k) {
            return nums[l];
        } else if (l + 1 < k) {
            return helper(nums, k, l + 1, right);
        } else {
            return helper(nums, k, left, l);
        }
    }
};
```

当然还可以用自带的第 N 大的函数，当然这是「偷懒」了。

```cpp
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }
};
```
