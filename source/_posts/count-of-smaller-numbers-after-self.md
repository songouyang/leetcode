---
title: 315. Count of Smaller Numbers After Self
date: 2019-03-04 11:27:37
tags:
alias: 315/
---

给定一个数组，求出每个元素的右边比本身小的元素的个数。

<!--more-->

用插入法，并使用二分搜索降低时间复杂度。

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> result(nums.size()), tmp;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int d = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), nums[i]));
            result[i] = d;
            tmp.insert(tmp.begin() + d, nums[i]);
        }
        return result;
    }
};
```

别人的提交里还有用树状数组的。这个思路之前做过的，在 [307. Range Sum Query - Mutable](https://songouyang.github.io/leetcode/range-sum-query-mutable/) 中使用过。

![树状数组](https://ws3.sinaimg.cn/large/e2a28cd6ly1g0qltp3lzpj20dw08xdg2.jpg)

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        if (nums.empty()) return vector<int>{};
        int min_v = *min_element(nums.begin(), nums.end());
        int max_v = *max_element(nums.begin(), nums.end());

        vector<int> BITree = vector<int>(max_v - min_v + 2, 0);
        vector<int> res = vector<int>(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i] - min_v + 1;
            res[i] = getSum(BITree, num - 1);
            update(BITree, num);
        }
        return res;
    }

    void update(vector<int> &BITree, int idx) {
        for (int i = idx; i < BITree.size(); i += (i & -i)) {
            BITree[i]++;
        }
    }

    int getSum(vector<int> &BITree, int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += BITree[idx];
            idx -= idx & -idx;
        }
        return ans;
    };
};
```
