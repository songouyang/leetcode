---
title: 287. Find the Duplicate Number
date: 2019-02-25 12:58:20
tags:
alias: 287/
---

找出数组中重复的数字。

<!--more-->

将值作为二分搜索的判断依据。注意不是下标，而是数组中的值。

```cpp
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid) ++count;
            }
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

还有一种解法是利用快慢指针，找出环的起点。

```cpp
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        if (nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};
```
