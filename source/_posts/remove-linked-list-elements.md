---
title: 203. Remove Linked List Elements
date: 2018-12-16 23:57:27
tags:
alias: 203/
---

移除链表中的某些节点。

<!--more-->

我用的是非递归的方法。

```cpp
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        auto *dump = new ListNode(-1);
        auto *p = dump;
        while (head) {
            if (head->val != val) {
                p->next = head;
                p = p->next;
            }
            head = head->next;
        }
        p->next = nullptr;
        return dump->next;
    }
};
```

讨论区还有递归的方法。

```cpp
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
```
