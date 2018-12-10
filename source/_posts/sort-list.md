---
title: 148. Sort List
date: 2018-12-09 17:17:22
tags:
alias: 148/
---

对链表排序，要求时间复杂度是 `O(nlogn)`。

<!--more-->

因为时间复杂度有了对数，需要考虑一下分治的思想。首先找到中点，然后左右两边都递归调用排序函数。其中快慢指针找中点的方法可以参考 [143. Reorder List](https://songouyang.github.io/leetcode/reorder-list/)。

```cpp
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        auto fast = head->next;
        auto slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(fast);
        return helper(left, right);
    }

    ListNode *helper(ListNode *left, ListNode *right) {
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        auto dump = new ListNode(-1);
        auto p = dump;
        while (left && right) {
            if (left->val > right->val) {
                p->next = right;
                right = right->next;
            } else {
                p->next = left;
                left = left->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        return dump->next;
    }
};
```
