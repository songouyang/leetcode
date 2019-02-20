---
title: 239. Sliding Window Maximum
date: 2019-02-20 23:27:27
tags:
alias: 239/
---

用一个大小为 k 的划窗在数组上滑动，求滑动的时候，划窗内的最大数字。

<!--more-->

参考了讨论区的答案。使用了双向队列，用来存储下标。
当左边的下标等于 `i-k` 说明队列已经达到最大值 `k`，需要把左边的一个值 `pop`。
如果当前值比右边的值大，说明队列中右边的值在本值进入后都不可能成为最大值了，把它们都移除。然后把本值加入右边。
当循环到了 `k` 之后，就肯定有最大值加入结果数组中了。

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) result.push_back(nums[q.front()]);
        }
        return result;
    }
};
```

这个想法💡真厉害！
