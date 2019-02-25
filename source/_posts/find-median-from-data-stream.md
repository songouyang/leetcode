---
title: 295. Find Median from Data Stream
date: 2019-02-25 15:22:05
tags:
alias: 295/
---

设计一个数据接口，它能够添加数字和找出中位数来。

<!--more-->

用两个堆，一个大堆存比中位数小的数字，一个小堆存比中位数大的数字。

```cpp
class MedianFinder {
public:
    priority_queue<int> small, large;

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() == large.size() ? (small.top() - large.top()) / 2.0 : small.top();
    }
};
```

同理的写法。

```cpp
class MedianFinder {
public:
    priority_queue<int> minQ;
    priority_queue<int, vector<int>, greater<int>> maxQ;

    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        int mn = minQ.empty() ? INT_MIN : minQ.top();
        (num > mn) ? maxQ.push(num) : minQ.push(num);
        if (minQ.size() > maxQ.size() + 1) {
            int mnmx = minQ.top();
            minQ.pop();
            maxQ.push(mnmx);
        } else if (minQ.size() + 1 < maxQ.size()) {
            int mxmn = maxQ.top();
            maxQ.pop();
            minQ.push(mxmn);
        }
    }

    double findMedian() {
        if (minQ.size() < maxQ.size()) return maxQ.top();
        else if (minQ.size() > maxQ.size()) return minQ.top();
        return 0.5 * (minQ.top() + maxQ.top());
    }
};
```
