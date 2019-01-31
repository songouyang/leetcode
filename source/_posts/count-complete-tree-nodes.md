---
title: 222. Count Complete Tree Nodes
date: 2019-01-31 23:10:01
tags:
alias: 222/
---

求完全二叉树的节点个数。

<!--more-->

第一眼没看清楚题目，直接当成普通二叉树了。

```cpp
class Solution {
public:
    int countNodes(TreeNode *root) {
        return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
    }
};
```

![image](https://ws2.sinaimg.cn/large/e2a28cd6gy1fzq6bsvffkj21t20uqaeg.jpg)

但是这个时间居然差不多，幸好看了评论区才发现看错题目了。

既然是完全二叉树。那么如果左右两边的高度一样的话，那么左边就是完全是满的。如果左右两边高度不一样的话，那么说明右边的高度这一层是填满的。

```cpp
class Solution {
public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh == rh) {
            return (1 << lh) + countNodes(root->right);
        }
        return (1 << rh) + countNodes(root->left);
    }

    int height(TreeNode *root) {
        int result = 0;
        while (root) {
            result += 1;
            root = root->left;
        }
        return result;
    }
};
```
