---
title: 331. Verify Preorder Serialization of a Binary Tree
date: 2019-03-07 17:15:21
tags:
alias: 331/
---

验证一个字符串是不是可以反序列化成一个二叉树。

<!--more-->

能够反序列化的字符串应该满足以下的条件：

1. 最后必须是 `#`
2. 从左到右的过程中，保持 `#` 的数量更多，可以保持相等。

```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream in(preorder);
        string buf = "";
        int count = 1;
        bool flag = false;
        while (getline(in, buf, ',')) {
            if (flag) return false;
            if (buf == "#") {
                if (--count == 0) flag = true;
            } else {
                ++count;
            }
        }
        return count == 0;
    }
};
```
