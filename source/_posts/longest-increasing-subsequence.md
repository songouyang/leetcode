---
title: 300. Longest Increasing Subsequence
date: 2019-02-25 23:47:55
tags:
alias: 300/
---

最长递增子序列。

<!--more-->

用动态规划，时间复杂度是 `O(n^2)`。

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

二分搜索法，用数组记录目前的最长递增序列。遇到比最后一个还大的数字，直接插入到最后，否则二分搜索找到下标并插入。

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> result = {nums[0]};
        for (int num : nums) {
            if (num > result.back()) result.push_back(num);
            else {
                int index = helper(result, num);
                result[index] = num;
            }
        }
        return result.size();
    }

private:
    int helper(vector<int> &result, int flag) {
        int left = 0, right = result.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (result[mid] < flag) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```
