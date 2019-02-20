---
title: 234. Palindrome Linked List
date: 2019-02-20 18:00:52
tags:
alias: 234/
---

判断一个链表是不是回文对称的。

<!--more-->

用快慢指针找出中点，在找中点的过程成顺便把左边的链表反转一下。

```cpp
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *pre = nullptr, *tmp = nullptr, *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        if (fast) slow = slow->next;
        while (slow && pre) {
            if (slow->val != pre->val) return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
```
