---
title: 297. Serialize and Deserialize Binary Tree
date: 2019-02-25 16:06:33
tags:
alias: 297/
---

实现二叉树的序列化与反序列化。

<!--more-->

自由度十分高，只要能完成序列化和反序列化即可。前序遍历，并且用逗号分割开来，判断分割的依据。

```cpp
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "#") return nullptr;
        stringstream s(data);
        return helper(s);
    }

private:
    TreeNode *helper(stringstream &s) {
        string buf;
        getline(s, buf, ',');
        if (buf == "#") { return nullptr; }
        else {
            auto root = new TreeNode(stoi(buf));
            root->left = helper(s);
            root->right = helper(s);
            return root;
        }
    }
};
```
