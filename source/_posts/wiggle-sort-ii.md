---
title: 324. Wiggle Sort II
date: 2019-03-05 16:30:55
tags:
alias: 324/
---

摆动排序，就是一会大于，一会小于。

<!--more-->

思路很简单，比如说。
先把数组排序好，然后从左到右填到奇数的下标，从右到左填到偶数的下标。但是这样的方法是空间复杂度 `O(n)`，时间复杂度是 `O(nlgn)`。

看了网上的分享，知道了下面的解法。首先找到中间大小的数字 `mid`。然后把小于该数字的数字放到奇数位置，大于的放在偶数位置。注意它的宏，就是一个下标对应函数。`nth_element` 会把数组排序好，把小于 `mid` 的数字下标 0、1、2 会对应到 1、3、5 上。而大于的数字下标 3、4、5 会对应到 0、2、4 上了。

```cpp
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
#define index(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size(), i = 0, j = 0, k = n - 1;
        auto midptr = nums.size() / 2 + nums.begin();
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        while (j <= k) {
            if (index(j) > mid) {
                swap(index(i++), index(j++));
            } else if (index(j) < mid) {
                swap(index(j), index(k--));
            } else {
                j++;
            }
        }
    }
};
```
