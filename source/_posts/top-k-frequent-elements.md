---
title: 347. Top K Frequent Elements
date: 2019-03-15 14:23:14
tags:
alias: 347/
---

找出数组中出现次数前 k 的元素。

<!--more-->

用 map 记录数字出现的字数，用优先队列对次数进行排序。

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        for (auto num: nums) {
            umap[num]++;
        }
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > umap.size() - k) {
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
    }
};
```
