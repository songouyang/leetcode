---
title: 210. Course Schedule II
date: 2018-12-18 10:55:25
tags:
alias: 210/
---

和 [207. Course Schedule](https://songouyang.github.io/leetcode/course-schedule/) 相比，这里要找出其中一种的安排。

<!--more-->

我这里改装一下之前的 DFS 答案。

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses, vector<int>());
        for (const auto &it : prerequisites) {
            graph[it.first].push_back(it.second);
        }
        vector<int> status(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (status[i] == 0) {
                if (!helper(graph, status, i, result)) {
                    break;
                }
            }
        }
        if (result.size() != numCourses) result.clear();
        return result;
    }

    bool helper(vector<vector<int>> &graph, vector<int> &status, int i, vector<int> &result) {
        if (status[i] == 2) return true;
        if (status[i] == 1) return false;
        status[i] = 1;
        for (const auto &it : graph[i]) {
            if (!helper(graph, status, it, result)) {
                return false;
            }
        }
        status[i] = 2;
        result.push_back(i);
        return true;
    }
};
```

当然也可以改装 BFS 答案。

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<int> result;
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
            result.push_back(tmp);
            for (const auto &it : graph[tmp]) {
                --indegree[it];
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (result.size() != numCourses) result.clear();
        std::reverse(result.begin(), result.end());
        return result;
    }
};
```

为啥最要还要反转一下？因为这是我之前答案的坑，之前就把顺序搞反了，但是之前只要判断有没有，当时没啥关系。所以如果不想看到这句话，那么把 `graph` 初始化的 `first` 和 `second` 反转一下了。
