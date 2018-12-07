---
title: 138. Copy List with Random Pointer
date: 2018-12-07 19:49:33
tags:
alias: 138/
---

深层复制一个链表，这个链表中的节点含有一个随机指针，可以指向链表中的任意一个节点。

<!--more-->

这不是和之前的深层复制图 [133. Clone Graph](/clone-graph/) 一样嘛。

```cpp
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (mp.find(head) == mp.end()) {
            mp[head] = new RandomListNode(head->label);
            mp[head]->next = copyRandomList(head->next);
            mp[head]->random = copyRandomList(head->random);
        }
        return mp[head];
    }

private:
    unordered_map<RandomListNode *, RandomListNode *> mp;
};
```

但是其实比起 [133](/clone-graph/) 题，这一题其实还有优化的空间。可以把空间复杂度从 `O(n)` 优化到 `O(1)`。


```cpp
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *iter = head;
        RandomListNode *next;
        while (iter) {
            next = iter->next;
            auto clone = new RandomListNode(iter->label);
            iter->next = clone;
            clone->next = next;
            iter = next;
        }
        iter = head;
        while (iter) {
            if (iter->random) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        iter = head;
        auto dump = new RandomListNode(-1);
        RandomListNode *copy, *copyIter = dump;
        while (iter) {
            next = iter->next->next;
            copy = iter->next;
            copyIter->next = copy;
            copyIter = copyIter->next;
            iter->next = next;
            iter = iter->next;
        }
        return dump->next;
    }
};
```

1. 在原链表的节点后面插入一个复制的节点。
2. 把复制的节点的 `random` 指针参考原链表的 `random` 指针指向适当的位置。
3. 拆分原链表和复制的新链表。
