---
title: 167. Two Sum II - Input array is sorted
date: 2018-12-11 12:15:02
tags:
alias: 167/
---

求数组中的两个数字加起来等于某个给定的值。

<!--more-->

左右两个双指针，然后比较加起来的大小，来确定移动两个指针。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result(2, -1);
        const auto n = numbers.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int count = numbers[i] + numbers[j];
            if (count == target) {
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            } else if (count > target) {
                --j;
            } else {
                ++i;
            }
        }
        return result;
    }
};
```
