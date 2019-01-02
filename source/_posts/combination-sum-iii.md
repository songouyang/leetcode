---
title: 216. Combination Sum III
date: 2019-01-02 19:52:05
tags:
alias: 216/
---

求 `k` 个 `1` 到 `9` 的数字加起来等于 `n`，把所有的组合方式都列出来。

<!--more-->

用 DFS 即可。终止的条件就是数组大小是 `k`，并且把 `n` 消耗完毕。

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> tmp;
        helper(result, tmp, 1, n, k);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &tmp, int start, int n, int k) {
        if (k == tmp.size() && n == 0) {
            result.push_back(tmp);
            return;
        }
        if (tmp.size() > k) return;
        for (int i = start; i <= 9; ++i) {
            tmp.push_back(i);
            helper(result, tmp, i + 1, n - i, k);
            tmp.pop_back();
        }
    }
};
```
