---
title: 229. Majority Element II
date: 2019-02-20 17:03:22
tags:
alias: 229/
---

找个个数超过 `1/3` 的所有元素。

<!--more-->

这样的元素不会超过 2 个。所以设定为 `candidate1` 和 `candidate2`。然后进行投票，投完票之后找出候选元素，最后遍历一次确定个数是否符合题意。

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> result;
        if (nums.empty()) return result;
        int candidate1 = nums[0], candidate2 = nums[0], count1 = 0, count2 = 0;
        for (auto &num: nums) {
            if (num == candidate1) {
                count1 += 1;
            } else if (num == candidate2) {
                count2 += 1;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 += 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 += 1;
            } else {
                count1 -= 1;
                count2 -= 1;
            }
        }
        int countA = 0, countB = 0;
        for (auto &num: nums) {
            if (num == candidate1) {
                countA += 1;
            } else if (num == candidate2) {
                countB += 1;
            }
        }

        if (countA > nums.size() / 3) {
            result.push_back(candidate1);
        }
        if (countB > nums.size() / 3) {
            result.push_back(candidate2);
        }
        return result;
    }
};
```
