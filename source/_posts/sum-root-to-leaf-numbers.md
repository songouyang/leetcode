---
title: 129. Sum Root to Leaf Numbers
date: 2018-12-06 20:59:25
tags:
alias: 129/
---

把从顶部到底部组成一个数字，并把所有路径组成的数字相加。

<!--more-->

每深入一层，就把中间变量乘以 10，然后 `result` 要加上乘以 10 后的结果并加上当前节点的值（作为个位数）。

```cpp
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        helper(root, 0);
        return result;
    }

    void helper(TreeNode *root, int tmp) {
        if (!root) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            result += 10 * tmp + root->val;
            return;
        }
        helper(root->left, 10 * tmp + root->val);
        helper(root->right, 10 * tmp + root->val);
    }

private:
    int result = 0;
};
```

注意的话，这里只有到了叶子节点才把结果加入到 `result` 中。
