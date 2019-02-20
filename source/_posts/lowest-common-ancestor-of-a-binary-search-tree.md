---
title: 235. Lowest Common Ancestor of a Binary Search Tree
date: 2019-02-20 18:13:41
tags:
alias: 235/
---

在二叉搜索树中找出两个节点的最小祖先。

<!--more-->

如果两个分别位于 `root` 的左右两边，那么 `root` 就是所求节点。如果两个点都小于 `root` 的话，那么就对左子树进行递归。如果两个点都大于 `root` 的话，那么就对右子树进行递归。

```cpp
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return root;
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if (root->val == p->val) {
            return p;
        } else if (root->val == q->val) {
            return q;
        } else if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
```
