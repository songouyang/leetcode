---
title: 232. Implement Queue using Stacks
date: 2019-02-20 17:16:59
tags:
alias: 232/
---

用栈实现队列。

<!--more-->

这个题目和 [225. Implement Stack using Queues](https://songouyang.github.io/leetcode/implement-stack-using-queues/) 相对。队列是先进先出，栈是先进后出。用两个队列来实现，当 `push` 的时候进行倒转一下。想像成倒豆子。

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s1.empty()) {
            int e = s1.top();
            s1.pop();
            s2.push(e);
        }
        s1.push(x);
        while (!s2.empty()) {
            int e = s2.top();
            s2.pop();
            s1.push(e);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int e = s1.top();
        s1.pop();
        return e;
    }

    /** Get the front element. */
    int peek() {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};
```
