---
title: 283. Move Zeroes
date: 2019-02-25 12:54:26
tags:
alias: 283/
---

把数组的 0 全部挪到最后。

<!--more-->

把非零的数字往前挪动，然后把后面的都填成 0 即可。

```cpp
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0, j = 0, n = nums.size();
        while (j < n) {
            while (j < n && nums[j] == 0) {
                ++j;
            }
            if (j < n) nums[i++] = nums[j++];
        }
        for (int l = i; l < n; ++l) {
            nums[l] = 0;
        }
    }
};
```
