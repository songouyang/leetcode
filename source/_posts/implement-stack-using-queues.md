---
title: 225. Implement Stack using Queues
date: 2019-02-19 10:32:19
tags:
alias: 225/
---

使用队列实现栈。

<!--more-->

队列是先进先出，栈是先进后出。用两个队列来实现，当 `push` 的时候进行倒转一下。

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            int e = q1.front();
            q1.pop();
            q2.push(e);
        }
        auto tmp_q = q1;
        q1 = q2;
        q2 = tmp_q;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int e = q1.front();
        q1.pop();
        return e;
    }

    /** Get the top element. */
    int top() {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};
```
