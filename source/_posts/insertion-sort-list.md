---
title: 147. Insertion Sort List
date: 2018-12-09 16:37:58
tags:
alias: 147/
---

使用插入排序对链表排序。

<!--more-->

从小到大往 `dump` 节点后面加，如果遇到后面的值比本身大的，就插入到它前面就可以。因为链表的特性，只能先拿到需要插入的位置的前一个点，然后插入到其后面才行。

```cpp
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        auto dump = new ListNode(INT_MIN);
        ListNode *next = nullptr;
        ListNode *p = nullptr;
        while (head) {
            next = head->next;
            p = dump;
            while (p->next && p->next->val < head->val) {
                p = p->next;
            }
            head->next = p->next;
            p->next = head;
            head = next;
        }
        return dump->next;
    }
};
```
