---
title: 116. Populating Next Right Pointers in Each Node
date: 2018-12-05 23:12:30
tags:
alias: 116/
---

将树中所有节点的 `next` 指针按照层序连接起来。

<!--more-->

题目中说明了，这是一颗完全二叉树。而且默认的话每个节点的 `next` 指针是 `NULL`。所以判断条件也很简单，如果左右节点都存在，就把左节点指向右节点。对于右节点的话，如果根节点存在 `next` 节点，那么右节点的 `next` 指针就指向根节点的 `next` 节点的左节点。最后左右子树都递归一下即可。

```cpp
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (root->left and root->right) {
            root->left->next = root->right;
        }
        if (root->right and root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
```
