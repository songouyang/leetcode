---
title: 113. Path Sum II
date: 2018-12-05 21:25:24
tags:
alias: 113/
---

找出所有从根节点到叶子节点的路径，其中这些路径要满足节点上的数字之和等于给定的数值。

<!--more-->

这里很明显的是 DFS，所以构造一个 `helper` 函数，用来找满足条件的路径。对于某个节点来说，如果左子树或者右子树找到加起来等于 `sum-(root->val)` 的路径就说明存在满足题意的路径，这就是递归关系式了。递归终止的条件就是到了叶子节点，不能继续往下了。如果到了叶子节点，并且正好把 `sum` 消耗完毕，就把这个路径添加到结果中。

```cpp
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        helper(root, sum, path, paths);
        return paths;
    }

    void helper(TreeNode* root, int sum, vector<int>&path, vector<vector<int>>&paths){
        if (!root){
            return;
        }
        path.push_back(root->val);
        if(!root->left && !root->right && sum==root->val){
            paths.push_back(path);
        }
        helper(root->left, sum-(root->val),path,paths);
        helper(root->right, sum-(root->val),path,paths);
        path.pop_back();
    }
};
```

需要注意的是：在 DFS 中，`helper` 函数一定要记得 `pop`，因为当回退路径的时候，不能把之前走过的路径带入下次尝试的路径中。
