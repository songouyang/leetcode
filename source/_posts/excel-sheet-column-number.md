---
title: 171. Excel Sheet Column Number
date: 2018-12-11 13:16:13
tags:
alias: 171/
---
将 Excel 中的头的形式转化为数字，和 [168. Excel Sheet Column Title](https://songouyang.github.io/leetcode/excel-sheet-column-title/) 正好相反。

<!--more-->

迭代一下就好了。

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result = 26 * result + (int) (s[i] - 'A') + 1;
        }
        return result;
    }
};
```
