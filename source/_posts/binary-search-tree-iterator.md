---
title: 173. Binary Search Tree Iterator
date: 2018-12-11 19:58:32
tags:
alias: 173/
---

实现一个二叉树的迭代器。

<!--more-->

需要实现的功能：是否还有下一个；下一个最小节点。

因为二叉树的最小节点都在左边，同时需要注意当栈里的一个节点 `pop` 出来之后，应该把它右孩子也进行一次左边的入栈，因为这样才保证了遍历了整个树了。

```cpp
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            _s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_s.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto result = _s.top();
        _s.pop();
        auto tmp = result->right;
        while (tmp) {
            _s.push(tmp);
            tmp = tmp->left;
        }
        return result->val;
    }

private:
    stack<TreeNode *> _s;
};
```
