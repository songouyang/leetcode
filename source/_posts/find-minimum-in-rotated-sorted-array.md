---
title: 153. Find Minimum in Rotated Sorted Array
date: 2018-12-10 11:38:16
tags:
alias: 153/
---

一个递增数组绕着中间某个轴反转了一次，求数组中的最小值。

<!--more-->

即使反转了一次，但是总还是有一半是递增的。所以先取中点，判断左边还是右边是单调的，因为如果是单调递增的话，最小值肯定在另外一边。换句话说有最小值的那半，不会是单调递增的。但是分半后就不定了，因为可能把 `mid` 那个点没有加入下次的循环。这也就是为什么 `while` 循环里面还要判断一次是不是可以直接跳出循环。

```cpp
class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] < nums[j]) {
                break;
            }
            int mid = i + (j - i) / 2;
            if (nums[mid] >= nums[i]) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return nums[i];
    }
};
```
