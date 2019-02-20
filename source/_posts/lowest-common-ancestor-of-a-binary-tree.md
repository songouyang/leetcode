---
title: 236. Lowest Common Ancestor of a Binary Tree
date: 2019-02-20 18:17:42
tags:
alias: 236/
---

在二叉树中找出两个节点的最小祖先。

<!--more-->

要点，如果 `root` 等于两个点的一个，那么 `root` 就是所求结果。如果不是的话，那么分别对左右字数求最小祖先，如果两边都求到了，那么 `root` 就是所求结果，否则就是左右两边不为空的节点。

```cpp
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        } else if (left) {
            return left;
        } else {
            return right;
        }
    }
};
```
