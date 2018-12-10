---
title: 160. Intersection of Two Linked Lists
date: 2018-12-10 14:15:42
tags:
alias: 160/
---

求两个链表开始相交的点。

<!--more-->

假设起点分别是 A、B，相交的点是 C，结尾的点是 D。那么让 `p` 指针走 AC + CD + BC，让 `q` 指针走 BC + CD + AC。因为路程相同，速度相同，所以肯定 C 点相遇。如果不存在相交的点呢，那么 C 点就是 `nullptr`，同样也会跳出 `while` 循环。

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA;
        auto q = headB;
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return q;
    }
};
```
