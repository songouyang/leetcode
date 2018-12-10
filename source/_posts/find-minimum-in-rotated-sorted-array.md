---
title: 153. Find Minimum in Rotated Sorted Array
date: 2018-12-10 11:38:16
tags:
alias: 153/
---

一个递增数组绕着中间某个轴反转了一次，求数组中的最小值。

<!--more-->

即使反转了一次，但是总还是有一半是递增的。先判断本身是不是单调递增的，如果本身是的话，那么最左边的就是最小值了。否则的话，先取中点，判断左边还是右边是单调的，如果 `mid` 大于等于 `i`，说明最小值在右边。如果 `mid` 小于 `i`，说明最小值在左边。

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
