---
title: 145. Binary Tree Postorder Traversal
date: 2018-12-09 11:28:58
tags:
alias: 145/
---

二叉树的后序遍历。
<!--more-->

如果使用递归，那么很简单就可以做出来了。

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        vector<int> left_result = postorderTraversal(root->left);
        vector<int> right_result = postorderTraversal(root->right);
        result.insert(result.end(), left_result.begin(), left_result.end());
        result.insert(result.end(), right_result.begin(), right_result.end());
        result.push_back(root->val);
        return result;
    }
};
```

如果不使用递归，可以自己管理入栈出栈即可。

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> result;
        TreeNode *p = root;
        TreeNode *pre = nullptr;
        if (!root) {
            return {};
        }
        s.push(p);
        while (!s.empty()) {
            p = s.top();
            if ((!p->left && !p->right) ||
                (pre && (pre == p->right || pre == p->left))) {
                result.push_back(p->val);
                s.pop();
                pre = p;
            } else {
                if (p->right) {
                    s.push(p->right);
                }
                if (p->left) {
                    s.push(p->left);
                }
            }
        }
        return result;
    }
};
```

如果还想优化空间复杂度的话，可以使用 Morris 遍历。具体详细信息查看 [Morris 遍历二叉树](https://www.ouyangsong.com/posts/27490/#%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86)。

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode dump(-1);
        dump.left = root;
        TreeNode *cur = &dump;
        TreeNode *pre = nullptr;
        vector<int> result;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    printReverse(cur->left, pre, result);
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return result;
    }

    void printReverse(TreeNode *from, TreeNode *to, vector<int> &result) {
        Reverse(from, to);
        TreeNode *p = to;
        while (true) {
            result.push_back(p->val);
            if (p == from) {
                break;
            }
            p = p->right;
        }
        Reverse(to, from);
    }

    void Reverse(TreeNode *from, TreeNode *to) {
        TreeNode *x = from;
        TreeNode *y = from->right;
        TreeNode *z;
        if (from == to) {
            return;
        }
        x->right = nullptr;
        while (x != to) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
};
```
