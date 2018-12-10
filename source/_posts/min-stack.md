---
title: 155. Min Stack
date: 2018-12-10 14:04:53
tags:
alias: 155/
---

实现一个可以获取当前最小值的栈。

<!--more-->

用另外一个 `stack` 来存储某个高度下的最小值。

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        _s.push(x);
        _min.push(_min.empty() ? x : min(x, _min.top()));
    }

    void pop() {
        _s.pop();
        _min.pop();
    }

    int top() {
        return _s.top();
    }

    int getMin() {
        return _min.top();
    }

private:
    stack<int> _min;
    stack<int> _s;
};
```
