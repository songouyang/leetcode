---
title: 125. Valid Palindrome
date: 2018-12-06 16:56:43
tags:
alias: 125/
---

判断是否为回文字符串。

<!--more-->

左右两边同时扫，遇到不是数字和字母的跳过。然后比较小写字符是否相等。

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        const auto n = s.length();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                ++i;
            }
            while (i < j && !isalnum(s[j])) {
                --j;
            }
            if (char(tolower(s[i])) == char(tolower(s[j]))) {
                ++i;
                --j;
            } else {
                return false;
            }
        }
        return true;
    }
};
```
