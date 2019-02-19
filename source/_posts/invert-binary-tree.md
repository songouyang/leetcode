---
title: 226. Invert Binary Tree
date: 2019-02-19 10:34:46
tags:
alias: 226/
---

镜像反转二叉树。

<!--more-->

用递归法即可。

```cpp
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return root;
        auto tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};
```
