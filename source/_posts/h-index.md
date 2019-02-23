---
title: 274. H-Index
date: 2019-02-23 19:49:06
tags:
alias: 274/
---

求出数组的 H 指数。

<!--more-->

可以使用桶排序用来计数。下面使用 `sum` 用来计数。

```cpp
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> histogram(n + 1);
        for (auto &it: citations) {
            ++histogram[it > n ? n : it];
        }
        int sum = 0;
        for (int i = n; i >= 0; --i) {
            sum += histogram[i];
            if (sum >= i) {
                return i;
            }
        }
        return n;
    }
};
```

也可以直接对原数组从大到小排序。用 `i` 作为计数。

```cpp
class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); ++i) {
            if (i >= citations[i]) return i;
        }
        return citations.size();
    }
};
```
