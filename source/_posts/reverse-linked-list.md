---
title: 206. Reverse Linked List
date: 2018-12-17 11:47:25
tags:
alias: 206/
---

反转单链表。

<!--more-->

基本功，我用非递归实现的。

```cpp
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *dump = new ListNode(-1);
        while (head) {
            ListNode *p = dump->next;
            ListNode *q = head->next;
            dump->next = head;
            head->next = p;
            head = q;
        }
        return dump->next;
    }
};
```

不使用 `dump` 的话，那就原地反转。

```cpp
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        while (head) {
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
```

也可以用递归实现。

```cpp
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
```
