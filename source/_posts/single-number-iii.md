---
title: 260. Single Number III
date: 2019-02-22 16:42:03
tags:
alias: 260/
---

找出数组中只出现一次的两个数字。

<!--more-->

首先全部异或操作得到两个数字的异或结果。然后把该结果中的二进制的等于 1 的位数取出来，然后根据位数等于 1 还是 0 把原数组分成两份并且两次异或即可。

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> result(2, 0);
        for (auto num: nums) {
            if (num & diff) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        return result;
    }
};
```
