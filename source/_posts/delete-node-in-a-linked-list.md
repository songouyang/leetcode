---
title: 237. Delete Node in a Linked List
date: 2019-02-20 18:24:02
tags:
alias: 237/
---

给定一个节点，在链表中删除该节点。

<!--more-->

直接修改指向该节点的指针，使得它指向下一个节点。

```cpp
class Solution {
public:
    void deleteNode(ListNode *node) {
        *node = *(node->next);
    }
};
```
