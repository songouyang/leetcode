---
title: 349. Intersection of Two Arrays
date: 2019-03-15 14:24:57
tags:
alias: 349/
---

两个数组的交集。

<!--more-->

用 set 进行去重复。

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> result;
        for(const auto & num2: nums2){
            if(s.erase(num2)) result.push_back(num2);
        }
        return result;
    }
};
```
