---
title: 209. Minimum Size Subarray Sum
date: 2018-12-18 09:54:05
tags:
alias: 209/
---

找出最短的连续子序列，使得子序列之和大于给定的数字。

<!--more-->

`O(n)` 的方法就是采用双指针进行滑窗。如果目前的和大于目标值右边界增大，否则左边界增大。

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int i = 0, j = 0, result = nums.size() + 1, count = 0;
        for (j = 0; j < nums.size(); ++j) {
            count += nums[j];
            while (count >= s) {
                result = min(result, j - i + 1);
                count -= nums[i++];
            }
        }
        return result == nums.size() + 1 ? 0 : result;
    }
};
```

题目还要求用 `O(nlogn)` 的方法，也就是分治的思路。
新建一个数组 `sum`，其中 `sum[i]` 表示 `nums[0]` 到 `nums[i]` 的和。

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        const auto n = nums.size();
        vector<int> sums(n + 1, 0);
        int result = n + 1;
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        if (sums[n] < s) return 0;
        for (int i = 0; i <= n; ++i) {
            int left = i + 1, right = n + 1, count = s + sums[i];
            while (left < right) {
                int mid = (left + right) / 2;
                if (sums[mid] < count) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left == n + 1) break;
            result = min(result, left - i);
        }
        return result == sums.size() ? 0 : result;
    }
};
```
