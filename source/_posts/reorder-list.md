---
title: 143. Reorder List
date: 2018-12-09 11:04:20
tags:
alias: 143/
---

按照一前一后的顺序，重新对链表排序，要求不能替换节点的值，只可以改变节点的连接关系。

<!--more-->

这一题可以分成三部分。第一部分，快慢指针找到中点。第二部分，反转后面部分的链表。第三部分，两个链表交替连接。

```cpp
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!(head && head->next)) {
            return;
        }
        auto head1 = head;
        auto head2 = head->next;
        while (head2 && head2->next) {
            head1 = head1->next;
            head2 = head2->next->next;
        }
        ListNode *next = head1->next;
        head1->next = nullptr;
        head1 = next;

        ListNode *p = nullptr;
        head2 = head1->next;
        while (head2) {
            head1->next = p;
            p = head1;
            head1 = head2;
            head2 = head2->next;
        }
        head1->next = p;

        head2 = head;
        while (head1 || head2) {
            ListNode *tmp = head2->next;
            head2->next = head1;
            head2 = head1;
            head1 = tmp;
        }
    }
};
```
