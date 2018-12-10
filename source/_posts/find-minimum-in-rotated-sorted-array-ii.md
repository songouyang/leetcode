---
title: 154. Find Minimum in Rotated Sorted Array II
date: 2018-12-10 13:22:58
tags:
alias: 154/
---

和 [153. Find Minimum in Rotated Sorted Array](https://songouyang.github.io/leetcode/find-minimum-in-rotated-sorted-array/) 不同的地方是这里存在重复的数字。

<!--more-->

既然存在重复，那么判断的时候，如果是相等那么就无法判断出趋势。既然只要找出最小的，去掉这个重复的不会影响最终的结果，并且下次循环的时候 `mid` 还会变化。

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
            if (nums[mid] > nums[i]) {
                i = mid + 1;
            } else if (nums[mid] < nums[i]) {
                j = mid;
            } else {
                i++;
            }
        }
        return nums[i];
    }
};
```
