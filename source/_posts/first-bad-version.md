---
title: 278. First Bad Version
date: 2019-02-23 20:21:22
tags:
alias: 278/
---

找出第一个出错误的版本。

<!--more-->

二分搜索即可。这样我想起了 `git` 自带的二分搜索功能 `git bisect` 来查找出错误的 commit。

```cpp
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
