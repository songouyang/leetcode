---
title: 150. Evaluate Reverse Polish Notation
date: 2018-12-09 18:06:18
tags:
alias: 150/
---

实现一个简单的四则运算。

<!--more-->

很明显的使用栈，因为它优先计算后面的数字。

```cpp
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty()) {
            return 0;
        }
        stack<int> s;
        for (const auto &it: tokens) {
            if (it == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b * a);
            } else if (it == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b + a);
            } else if (it == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            } else if (it == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push((a == 0 || b == 0) ? 0 : b / a);
            } else {
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};
```
