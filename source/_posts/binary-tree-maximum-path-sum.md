---
title: 124. Binary Tree Maximum Path Sum
date: 2018-12-06 16:26:21
tags:
alias: 124/
---

找出某条路径，是的路径的所有节点之和最大。

<!--more-->

这个用 DFS 即可。`helper` 函数用来找以 `root` 为根的最大值路径，注意这里的路径是单路径，也就是不会在 `root` 这里转弯。其中 `result` 一定要用引用传入，因为内部递归会不断判断得到 `result` 的最大值。所以 `result` 的判断应该是左右两边的值加上根节点的值，如果左右某边小于 0，就不加上那边，我这里用 `max` 函数就实现了这个逻辑。

```cpp
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        helper(root, result);
        return result;
    }

    int helper(TreeNode *root, int &result) {
        if (!root) {
            return 0;
        }
        int tmp1 = max(helper(root->left, result), 0);
        int tmp2 = max(helper(root->right, result), 0);
        result = max(result, root->val + tmp1 + tmp2);
        return max(root->val + max(tmp1, tmp2), 0);
    }
};
```
