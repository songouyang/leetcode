---
title: 275. H-Index II
date: 2019-02-23 20:14:27
tags:
alias: 275/
---

这一题增加的条件是给出的数组是递增的。

<!--more-->

我直接从右到左遍历一次。时间复杂度是 `O(n)`。

```cpp
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        for (int i = n - 1; i >= 0; --i) {
            if (n - 1 - i >= citations[i]) return n - i - 1;
        }
        return n;
    }
};
```

发现还有人用二分搜索，比我快多了。

```cpp
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        if (n == 0) {
            return 0;
        }
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int len = n - mid;

            if (len == citations[mid]) {
                return citations[mid];
            }
            if (len < citations[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return n - r - 1;
    }
};
```
