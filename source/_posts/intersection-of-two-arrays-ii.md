---
title: 350. Intersection of Two Arrays II
date: 2019-03-15 14:26:24
tags:
alias: 350/
---

同样是两个数组求公共交集，但是这里要求交集中可以存在相同的数字。

<!--more-->

使用 map 用来计数。

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for(const auto & num1: nums1){
            umap[num1]++;
        }
        vector<int> result;
        for(const auto & num2: nums2){
            if(umap[num2]-- > 0){
                result.push_back(num2);
            }
        }
        return result;
    }
};
```
