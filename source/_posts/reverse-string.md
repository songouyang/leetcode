---
title: 344. Reverse String
date: 2019-03-15 13:53:08
tags:
alias: 344/
---

翻转字符串。

<!--more-->

```cpp
class Solution {
public:
    void reverseString(vector<char> &s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            char tmp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = tmp;
        }
    }
};
```
