---
title: 144. Binary Tree Preorder Traversal
date: 2018-12-09 11:14:31
tags:
alias: 144/
---

二叉树的前序遍历。

<!--more-->

如果使用递归，那么很简单就可以做出来了。

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        result.push_back(root->val);
        vector<int> left_result = preorderTraversal(root->left);
        vector<int> right_result = preorderTraversal(root->right);
        result.insert(result.end(), left_result.begin(), left_result.end());
        result.insert(result.end(), right_result.begin(), right_result.end());
        return result;
    }
};
```

如果不使用递归，可以自己管理入栈出栈即可。

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        if (root) {
            s.push(root);
        }
        while (!s.empty()) {
            TreeNode *e = s.top();
            result.push_back(e->val);
            s.pop();
            if (e->right) {
                s.push(e->right);
            }
            if (e->left) {
                s.push(e->left);
            }
        }
        return result;
    }
};
```

如果还想优化空间复杂度的话，可以使用 Morris 遍历。具体详细信息查看 [Morris 遍历二叉树](https://www.ouyangsong.com/posts/27490/#%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86)。

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        vector<int> result;
        while (cur) {
            if (!cur->left) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = cur;
                    result.push_back(cur->val);
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
```
