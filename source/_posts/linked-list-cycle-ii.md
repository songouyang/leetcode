---
title: 142. Linked List Cycle II
date: 2018-12-09 10:14:28
tags:
alias: 142/
---

和 [141. Linked List Cycle](/linked-list-cycle/) 相比，这次还需要找出环的起点。

<!--more-->

假设起点是 A，环的起点是 B，第一次相交的点是 C。那么第一次相遇的时候，到了 C 点。得出下面的等式。假设环的大小是 R。

> 2(AB + BC) = nR + AB + BC
> AB + BC = nR

同时又因为 `BC + CB = R`，所以得到：

> AB - CB = (n-1)R
> AB = CB + (n-1)R

所以只要当快慢指针相遇后，然后把快指针重新放到 `head` 上，接下来和慢指针以相同的速度移动就可以到环的起点了。

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        bool has_circle = false;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                has_circle = true;
                break;
            }
        }
        if (!has_circle) {
            return nullptr;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
```

