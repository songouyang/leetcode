---
title: 224. Basic Calculator
date: 2019-02-18 23:54:46
tags:
alias: 224/
---

实现一个简单的计算器，主要是解析字符串里面的加减法则。

<!--more-->

对于括号的话，需要把括号之前的符号记录下来放到栈中，遇到右括号就出栈。

```cpp
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                int total = 0;
                while (s[i] >= '0' && s[i] <= '9' && i < s.length()) {
                    total = 10 * total + (s[i++] - '0');
                }
                result += total * sign;
                --i;
            } else if (c == '(') {
                st.push(sign);
                st.push(result);
                sign = 1;
                result = 0;
            } else if (c == ')') {
                int pre_result = st.top();
                st.pop();
                int pre_sign = st.top();
                st.pop();
                result = pre_result + pre_sign * result;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '+') {
                sign = 1;
            }
        }
        return result;
    }
};
```
