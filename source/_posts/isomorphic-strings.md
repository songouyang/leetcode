---
title: 205. Isomorphic Strings
date: 2018-12-17 11:37:45
tags:
alias: 205/
---

判断两个字符串是不是同构的。

<!--more-->

需要把字母映射成上一次出现的下标。

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m[128] = {0}, n[128] = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (m[s[i]] != n[t[i]]) return false;
            m[s[i]] = n[t[i]] = i + 1;
        }
        return true;
    }
};
```

需要注意的就是这个下标为什么是 `i+1` 而不是用 `i` 代替呢？举个例子：`ab` 和 `aa`，因为默认都是从 0 开始的，所以如果用 `i` 代替的话，那么 `b` 和 `a` 也会判断成首次出现而不会将它们判断成不同。所以不能用 `i` 来表示它们上次出现的位置。
