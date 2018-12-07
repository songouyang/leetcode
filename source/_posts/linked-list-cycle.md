---
title: 141. Linked List Cycle
date: 2018-12-07 21:37:51
tags:
alias: 141/
---

判断单链表是不是存在环。

<!--more-->

经典的快慢指针。

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
```
