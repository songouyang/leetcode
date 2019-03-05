---
title: 321. Create Maximum Number
date: 2019-03-05 11:05:23
tags:
alias: 321/
---

用两个数组中的元素拼成一个数字，使得该数字最大的同时保持相对位置不变。

<!--more-->

首先分成若干个部分。
第一部分，给定一个数组，和要拿出的元素个数，求出能拿到的最大的子数组。
第二部分，给定两个数组，使得和最大的合并。
第三部分，就是比较两个数组，这在第二部分中也有使用。当两个相等的时候，比较后面的数组。如果前面都相等，那么就优先拿长的那个，这样才可以比较多余出来的那部分元素的大小。

```cpp
class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> result;
        for (int i = max(0, k - (int) nums2.size()); i <= min(k, (int) nums1.size()); ++i) {
            auto tmp = merge(getMax(nums1, i), getMax(nums2, k - i));
            if (cmp(tmp, 0, result, 0)) {
                result = tmp;
            }
        }
        return result;
    }

private:
    vector<int> getMax(vector<int> &nums, int k) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while ((stk.size() + nums.size() - i) > k && !stk.empty() && nums[i] > stk.back()) {
                stk.pop_back();
            }
            stk.push_back(nums[i]);
        }
        stk.resize(k);
        return stk;
    }

    bool cmp(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                return true;
            } else if (nums1[i] < nums2[j]) {
                return false;
            } else {
                ++i;
                ++j;
            }
        }
        return i < nums1.size();
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        int i = 0, j = 0;
        vector<int> result;
        while (i < nums1.size() && j < nums2.size()) {
            if (cmp(nums1, i, nums2, j)) {
                result.push_back(nums1[i++]);
            } else {
                result.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size()) result.push_back(nums1[i++]);
        while (j < nums2.size()) result.push_back(nums2[j++]);
        return result;
    }
};
```
