---
title: 328. Odd Even Linked List
date: 2019-03-07 15:42:51
tags:
alias: 328/
---

将链表按照奇偶的下标来重新组合。

<!--more-->

把奇偶分别接起来，然后把两个链表首尾连起来。

```cpp
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return head;
        auto tmp1 = head, tmp2 = head->next, tmp3 = head->next;
        while (tmp2 && tmp2->next) {
            tmp1->next = tmp2->next;
            tmp2->next = tmp2->next->next;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tmp1->next = tmp3;
        return head;
    }
};
```
