---
title: 117. Populating Next Right Pointers in Each Node II
date: 2018-12-05 23:49:18
tags:
alias: 117/
---

和 [116. Populating Next Right Pointers in Each Node](/populating-next-right-pointers-in-each-node/) 相比，这一题的二叉树不是完全二叉树，并且题目要求空间复杂度是 `O(1)`。

<!--more-->

增加一个哨兵节点 `dump`，这个节点的用作就是记录下一层的开头。首先 `p` 指针和 `dump` 一致的时候，会把 `dump` 的 `next` 指针指向下一层的第一个非空节点，所以可以得到下一层的开头。然后因为上一层已经连接完毕，所以可以不断移动 `root` 节点，来不断连接下一层。当 `root` 为空的时候说明上一层已经遍历完毕，然后把 `p` 指向回 `dump` 哨兵节点，因为前面说了 `dump` 的 `next` 是下一层的第一个非空节点，那么就可以把 `root` 指向 `p->next` 开始下一层的遍历了。接着把 `dump` 断开。假如不断开，并且 `root` 是叶子层的时候，下一层没有了非空节点，也就是说 `dump` 不会指向下一层了，还会继续连上这一层，然后 `root` 又变成本层的第一个非空节点，就进入死循环了。如果正常断开的话，那么到了叶子层，进行下一层的时候，`root` 变成了空，也就会跳出循环，完成连接任务了。

```cpp
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dump = new TreeLinkNode(-1);
        TreeLinkNode *p = dump;
        while (root) {
            if (root->left) {
                p->next = root->left;
                p = p->next;
            }
            if (root->right) {
                p->next = root->right;
                p = p->next;
            }
            root = root->next;
            if (!root) {
                p = dump;
                root = p->next;
                dump->next = NULL;
            }
        }
    }
};
```
