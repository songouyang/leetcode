---
title: 114. Flatten Binary Tree to Linked List
date: 2018-12-05 21:31:32
tags:
alias: 114/
---

将一个二叉树按照先序遍历展开成一个链表。

<!--more-->

假设左右子树都已经展开好了，只需要把根节点和右子树断开，然后把左子树移到右边，然后在把之前断开的右子树接到最右边即可。

```cpp
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) {
            root = root->right;
        }
        root->right = tmp;
    }
};
```

我这里写的很直接，就是直接按照想法来写的。发现讨论区有个很简洁的答案。

```cpp
class Solution {
private:
    TreeNode *prev = NULL;

public:
    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
```

因为最终输出结果是 `root -> left -> right`，所以程序中按照 `right -> left -> root` 的顺序展开，也就是从下往上垒起来。其中的 `prev` 是关键，因为先展开右子树的话，`prev` 就是右子树的根节点，然后计算左子树的时候，会不断递归找到左子树的最右值，并将它的右边连接上展开后的右子树。
