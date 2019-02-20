---
title: 230. Kth Smallest Element in a BST
date: 2019-02-20 17:06:25
tags:
alias: 230/
---

找出二叉搜索树中的第 k 小的元素。

<!--more-->

中序遍历，在遍历的同时计数，当计数到 k 的时候保存该节点的值即可。

```cpp
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int result;
        helper(root, k, result);
        return result;
    }

    void helper(TreeNode *root, int &k, int &result) {
        if (!root) return;
        helper(root->left, k, result);
        --k;
        if (k == 0) {
            result = root->val;
            return;
        }
        helper(root->right, k, result);
    }
};
```
