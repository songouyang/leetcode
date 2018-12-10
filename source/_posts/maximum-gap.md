---
title: 164. Maximum Gap
date: 2018-12-10 23:07:45
tags:
alias: 164/
---

求数值中的数字排序后的最大相邻间隔。

<!--more-->

题目要求时间复杂度是 `O(n)`，所以比较排序是不可能达到这种时间复杂度。可以参考这里 [经典排序算法](https://www.ouyangsong.com/posts/39573/)。所以这里使用非比较排序中的**桶排序**。

先找数组中的最大值和最小值，然后确定桶的容量 `gap`，接下来确定桶的个数。
用两组桶来保存每个区间内的最大值和最小值。我们要的结果是最大间隔，那么这两个数字肯定不会在同一个桶里面，肯定是前一个区间的最大值和后一个区间的最小值。我做的时候花了很长时间才想明白为啥是这样减一下求最大间隔。应该这样理解：每个区间内不存在最大间隔，但是可能存在若干个很小间隔数字，所以不能是前一个区间的最小值和后一个区间的最大值。只有前一个区间的最大值和后一个区间的最小值之间才不存在别的数字，而且我们要求的答案肯定存在它们的间隔之中。所以最后吧这些间隔的最大值取出来即可。
注意如果区间内是空的，就跳过这个区间，因为我们的最大间隔可能还是跨区间的。

```cpp
class Solution {
public:
    int maximumGap(vector<int> &nums) {
        const auto n = nums.size();
        if (n < 2) {
            return 0;
        }
        auto min_max = minmax_element(nums.begin(), nums.end());
        int l = *min_max.first;
        int h = *min_max.second;
        int gap = (h - l) / n + 1;
        int m = (h - l) / gap + 1;
        vector<int> bucket_min(n, INT_MAX);
        vector<int> bucket_max(n, INT_MIN);
        set<int> s;
        for (const auto &num: nums) {
            int loc = (num - l) / gap;
            bucket_min[loc] = min(bucket_min[loc], num);
            bucket_max[loc] = max(bucket_max[loc], num);
            s.insert(loc);
        }

        int pre = 0;
        int result = 0;
        for (int i = 1; i < n; ++i) {
            if (!s.count(i)) {
                continue;
            }
            result = max(bucket_min[i] - bucket_max[pre], result);
            pre = i;
        }
        return result;
    }
};
```
