---
title: 337. House Robber III
date: 2019-03-15 12:30:59
tags:
alias: 337/
---

相临的两个树节点不能被连续抢劫。

<!--more-->

本节点加上左子树和右子树的子节点，左子树和右子树的和，取两者的最大值。

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> umap;
        return helper(root, umap);
    }
private:
    int helper(TreeNode * root, unordered_map<TreeNode*, int>&umap){
        if(!root) return 0;
        if(umap.count(root)) return umap[root];
        int val = 0;
        if(root->left){
            val += helper(root->left->left, umap) + helper(root->left->right, umap);
        }
        if(root->right){
            val += helper(root->right->left, umap) + helper(root->right->right, umap);;
        }
        val = max(val + root->val, helper(root->left, umap)+helper(root->right, umap));
        umap[root] = val;
        return val;
    }
}
```
