---
title: 228. Summary Ranges
date: 2019-02-20 16:59:55
tags:
alias: 228/
---

把相邻的数字用摘要的方式表示出来。

<!--more-->

找规律即可。

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int flag = nums[0];
        for (int i = 1; i <= nums.size(); ++i) {
            if (i < nums.size() && nums[i] == nums[i - 1] + 1) {
                continue;
            } else {
                if (nums[i - 1] == flag) {
                    result.push_back(to_string(flag));
                } else {
                    result.push_back(to_string(flag) + "->" + to_string(nums[i - 1]));
                }
                flag = i == nums.size() ? 0 : nums[i];
            }
        }
        return result;
    }
};
```
