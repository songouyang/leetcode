---
title: 227. Basic Calculator II
date: 2019-02-20 16:53:43
tags:
alias: 227/
---

实现简单的计算器，需要实现加减乘除，需要注意运算顺序。

<!--more-->

可以用加减法把整个字符串分成若干个组，每个组里计算完后，然后再加起来。`sign` 就是用来记录每个组的关联的符号，`last_op` 则是用来记录组内运算的前一个运算符号，`last_result` 是用来记录组内已经累计的数值，`result` 是记录所有组累计的数值。

```cpp
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int last_result = 0;
        char last_op = '+';
        int sign = 1;
        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == '-' || s[i] == '+') {
                result += last_result * sign;
                sign = s[i] == '+' ? 1 : -1;
                last_result = 0;
                last_op = '+';
            } else if (s[i] == '*' || s[i] == '/') {
                last_op = s[i];
            } else if (s[i] >= '0' && s[i] <= '9') {
                int total = 0;
                while (s[i] >= '0' && s[i] <= '9' && i < s.length()) {
                    total = 10 * total + (s[i++] - '0');
                }
                --i;
                if (last_op == '*') {
                    last_result *= total;
                } else if (last_op == '/') {
                    last_result /= total;
                } else {
                    last_result = total;
                }
            }
        }
        return result;
    }
};
```

分享一下别人的答案。他主要是在 `s` 前后加上了加号，保证了前后得到的数值都可以最终累计到结果中。

```cpp
class Solution {
public:
    int calculate(string s) {
        int total = 0;
        int num = 0;
        s = '+' + s + '+';
        for (int i = 0; i < s.size();) {
            char op = s[i];
            if (isspace(op)) {
                ++i;
                continue;
            }
            if (op == '+' || op == '-') {
                total += num;
                num = 0;
                ++i;
                while (i < s.size() && (isdigit(s[i]) || isspace(s[i]))) {
                    if (isdigit(s[i]))
                        num = num * 10 + (s[i] - '0');
                    ++i;
                }
                num *= (op == '+') ? 1 : -1;
            } else {
                int temp = 0;
                ++i;
                while (i < s.size() && (isdigit(s[i]) || isspace(s[i]))) {
                    if (isdigit(s[i]))
                        temp = temp * 10 + (s[i] - '0');
                    ++i;
                }
                num = (op == '*') ? num * temp : num / temp;
            }
        }
        return total;
    }
};
```
