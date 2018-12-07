---
title: 133. Clone Graph
date: 2018-12-07 14:43:17
tags:
alias: 133/
---

实现一个图的深复制。

<!--more-->

使用 DFS，不断复制即可。`mp` 用来记录已经访问过的节点，防止遍历相同的节点，进入了死循环。其实 `mp` 的作用就是一个新旧图的节点对应关系。

```cpp
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return nullptr;
        }
        if (mp.find(node) == mp.end()) {
            mp[node] = new UndirectedGraphNode(node->label);
            for (const auto it:node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        return mp[node];
    }

private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
};
```
