---
title: 341. Flatten Nested List Iterator
date: 2019-03-15 13:07:49
tags:
alias: 341/
---

将一个多层数组打平，并得到迭代器。

<!--more-->

一种办法就是在算 next 的时候动态去获取下一个。

```cpp
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

    int next() {
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }

    bool hasNext() {
        while (!nodes.empty()) {
            auto curr = nodes.top();
            if (curr.isInteger()) return true;
            nodes.pop();
            for (int i = curr.getList().size() - 1; i >= 0; --i) {
                nodes.push(curr.getList()[i]);
            }
        }
        return false;
    }

private:
    stack<NestedInteger> nodes;
};
```

还有个办法就是初始化的时候就递归转化成一个数组。

```cpp
class NestedIterator {
public:
    void Fill(const vector<NestedInteger> &l) {
        for (const auto &i : l) {
            if (i.isInteger()) {
                list_.push_back(i.getInteger());
            } else {
                Fill(i.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        Fill(nestedList);
        idx_ = 0;
    }

    int next() {
        return list_[idx_++];
    }

    bool hasNext() {
        return idx_ != list_.size();
    }

private:
    vector<int> list_;
    int idx_;
};
```
