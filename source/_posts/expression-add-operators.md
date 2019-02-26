---
title: 282. Expression Add Operators
date: 2019-02-26 13:09:20
tags:
alias: 282/
---

给只包含数字的字符串中间加上加减乘号，使得运算结果等于目标数字。

<!--more-->

需要记录已经得到的数值 `cv`，上次运算的数值 `pv`。如果下次的运算符号是加减法很简单，但是如果是乘法的话，需要借用上次的运算符和上次的运算结果来判断。

```cpp
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        for (int i = 1; i <= num.size(); ++i) {
            string s = num.substr(0, i);
            long cv = stol(s);
            if (to_string(cv).size() != s.size()) continue;
            helper(num, target, i, result, cv, cv, s, "*");
        }
        return result;
    }

private:
    void helper(string num, int target, int i, vector<string> &result, long cv, long pv, string s, string op) {
        if (i == num.size() && cv == target) {
            result.push_back(s);
            return;
        }
        for (int j = 1; i + j <= num.size(); ++j) {
            string s1 = num.substr(i, j);
            long cv1 = stol(s1);
            if (to_string(cv1).size() != s1.size()) continue;
            helper(num, target, i + j, result, cv + cv1, cv1, s + "+" + s1, "+");
            helper(num, target, i + j, result, cv - cv1, cv1, s + "-" + s1, "-");
            if (op == "+") {
                helper(num, target, i + j, result, cv - pv + pv * cv1, pv * cv1, s + "*" + s1, op);
            } else if (op == "-") {
                helper(num, target, i + j, result, cv + pv - pv * cv1, pv * cv1, s + "*" + s1, op);
            } else if (op == "*") {
                helper(num, target, i + j, result, cv * cv1, pv * cv1, s + "*" + s1, op);
            }
        }
    }
};
```
