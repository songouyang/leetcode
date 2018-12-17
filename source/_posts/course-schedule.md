---
title: 207. Course Schedule
date: 2018-12-17 20:03:22
tags:
alias: 207/
---

判断按照已有的先决条件能不能有这样的安排。

<!--more-->

这其实就是图里面的拓扑排序。也就是是否存在这样线性排序，使得 u 都在 v 之前。

抽象出来就是图中不存在环，假设 a 要在 b 之前，那么存在一条由 a 到 b 的边；同时 b 要在 a 之前，那么存在一条由 b 到 a 的边，这样就形成了环。

我这里使用 DFS，用状态 0 代表还未访问，用 1 代表正在访问，用 2 代表已经访问过的点。

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (const auto &it : prerequisites) {
            graph[it.first].push_back(it.second);
        }
        vector<int> status(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (status[i] == 0) {
                if (!helper(graph, status, i)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<int>> &graph, vector<int> &status, int i) {
        if (status[i] == 2) return true;
        if (status[i] == 1) return false;
        status[i] = 1;
        for (const auto &it : graph[i]) {
            if (!helper(graph, status, it)) {
                return false;
            }
        }
        status[i] = 2;
        return true;
    }
};
```

改成 BFS 也是可以的。那么思路就稍微有点变化，这也叫作 Kahn 算法。也就是先找出入度为 0 的点，把它去除掉，同时把它相邻的边也去除掉。
用 `indegree` 代表某个点的入度，用 `graph` 代表由 `a` 到 `b` 的边，记录某个点的相邻的点。

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (const auto &it : prerequisites) {
            ++indegree[it.second];
            graph[it.first].push_back(it.second);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            ++count;
            for (const auto &it : graph[tmp]) {
                --indegree[it];
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count == numCourses;
    }
};
```
