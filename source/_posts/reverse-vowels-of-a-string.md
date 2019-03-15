---
title: 345. Reverse Vowels of a String
date: 2019-03-15 13:55:10
tags:
alias: 345/
---

翻转字符串，只翻转元音字母。

<!--more-->

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int a = 0, b = s.size() - 1;
        while (a < b) {
            while (a < b && !helper(s[a])) {
                ++a;
            }
            while (a < b && !helper(s[b])) {
                --b;
            }
            if (a < b) {
                swap(s[a++], s[b--]);
            }
        }
        return s;
    }

private:
    bool helper(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }
};
```
