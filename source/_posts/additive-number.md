---
title: 306. Additive Number
date: 2019-02-27 15:04:43
tags:
alias: 306/
---

把一个字符串拆成斐波那契数列。

<!--more-->

因为题目中说明了至少有 3 个数字，所以先切分两个数字出来，然后递归判断后面的是否满足条件即可。

```cpp
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.empty()) return false;
        for (int i = 1; i < num.length(); ++i) {
            string s1 = num.substr(0, i);
            long l1 = stol(s1);
            if (to_string(l1).size() != s1.size()) continue;
            else {
                for (int j = 1; i + j < num.length(); ++j) {
                    string s2 = num.substr(i, j);
                    long l2 = stol(s2);
                    if (to_string(l2).size() != s2.size()) continue;
                    else {
                        if (helper(l1, l2, num.substr(i + j))) return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool helper(long l1, long l2, string str) {
        if (str.empty()) return true;
        for (int i = 1; i <= str.length(); ++i) {
            string s = str.substr(0, i);
            long l = stol(s);
            if (to_string(l).size() != s.size()) return false;
            else if (l == l1 + l2) {
                return helper(l2, l, str.substr(i));
            } else if (l > l1 + l2) {
                break;
            }
        }
        return false;
    }
};
```
