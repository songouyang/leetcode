---
title: 257. Binary Tree Paths
date: 2019-02-21 11:22:49
tags:
alias: 257/
---

得到从二叉树的根到所有叶子节点的路径。

<!--more-->

用 `DFS` 即可。

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        if (!root) return result;
        helper(root, result, to_string(root->val));
        return result;
    }

    void helper(TreeNode *root, vector<string> &result, string str) {
        if (!root->left && !root->right) {
            result.push_back(str);
            return;
        }
        if (root->left) helper(root->left, result, str + "->" + to_string(root->left->val));
        if (root->right) helper(root->right, result, str + "->" + to_string(root->right->val));
    }
};
```
