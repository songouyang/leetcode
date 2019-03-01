---
title: 310. Minimum Height Trees
date: 2019-03-01 16:51:45
tags:
alias: 310/
---

在图中找出高度最小的树的顶点。

<!--more-->

其实就是找出拓扑图中最中间的一个点。所以采用剥洋葱法，从外围（度等于 1 的点）开始往里面剥。

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        if (n == 1) return {0};
        vector<int> result;
        queue<int> q;
        vector<unordered_set<int>> leaves(n, unordered_set<int>());
        for (const auto &edge: edges) {
            leaves[edge.first].insert(edge.second);
            leaves[edge.second].insert(edge.first);
        }
        for (int i = 0; i < n; ++i) {
            if (leaves[i].size() == 1) {
                q.push(i);
            }
        }
        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int u = q.front();
                q.pop();
                for (auto v: leaves[u]) {
                    leaves[v].erase(u);
                    if (leaves[v].size() == 1) q.push(v);
                }
            }
        }
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
```
