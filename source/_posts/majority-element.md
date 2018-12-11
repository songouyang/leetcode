---
title: 169. Majority Element
date: 2018-12-11 12:41:31
tags:
alias: 169/
---

找出数组中个数超过一半的数字。

<!--more-->

采用类似对战的思想，如果下一个数字和当前的相同就把计数加 1，否则就抵消一个，计数减去 1。最后剩下来的就是数量超过一半的数字。

```cpp
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0;
        int result;
        for (const auto &num:nums) {
            if (count == 0) {
                result = num;
                count++;
            } else {
                count += num == result ? 1 : -1;
            }
        }
        return result;
    }
};
```
