---
title: 290. Word Pattern
date: 2019-02-25 14:28:44
tags:
alias: 290/
---

单词的字母能不能一一映射到字符串的单词上。

<!--more-->

用两个哈希表来把字母或者单词映射到出现的下标上。

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::istringstream in(str);
        string buf;
        map<char, int> map1;
        map<string, int> map2;
        int n = pattern.length(), i = 0;
        while (in >> buf) {
            if (i == n) return false;
            if (map1[pattern[i]] != map2[buf]) return false;
            map1[pattern[i]] = map2[buf] = i + 1;
            ++i;
        }
        return i == n;
    }
};
```
