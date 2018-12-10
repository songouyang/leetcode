---
title: 151. Reverse Words in a String
date: 2018-12-10 11:13:23
tags:
alias: 151/
---

将字符串中的单词顺序反转一次。

<!--more-->

要求是只是对单词的顺序反转，单词内部的字母顺序不反转。注意可能中间存在若干个空格。先把整个字符串反转一次，然后每个单词中间间隔一个空格，并且把下一个单词移动到该空格后面。接下来把这个单词再反转回来，达到单词内部的字母顺序不反转的目的。

```cpp
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        unsigned long index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (index != 0) {
                    s[index++] = ' ';
                }
                int j = i;
                while (j < s.size() && s[j] != ' ') {
                    s[index++] = s[j++];
                }
                reverse(s.begin() + index - j + i, s.begin() + index);
                i = j;
            }
        }
        s = s.substr(0, index);
    }
};
```
