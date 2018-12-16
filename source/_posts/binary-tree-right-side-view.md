---
title: 199. Binary Tree Right Side View
date: 2018-12-16 20:34:54
tags:
alias: 199/
---

从右侧看二叉树，可以看到哪些节点。

<!--more-->

二叉树层序遍历的变形。

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto e = q.front();
                if (size == 0) {
                    result.push_back(e->val);
                }
                q.pop();
                if (e->left) q.push(e->left);
                if (e->right) q.push(e->right);
            }
        }
        return result;
    }
};
```
