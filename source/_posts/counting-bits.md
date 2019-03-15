---
title: 338. Counting Bits
date: 2019-03-15 12:45:45
tags:
alias: 338/
---

给定一个数字 n，求从 0 到 n 所有数字中用二进制表示的时候有多少个 1。

<!--more-->

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for(int i = 1;i<=num;++i){
            result[i] = result[i&(i-1)] + 1;
        }
        return result;
    }
};
```
