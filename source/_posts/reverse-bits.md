---
title: 190. Reverse Bits
date: 2018-12-16 17:42:52
tags:
alias: 190/
---

按照比特位来反转。

<!--more-->

想法很简单，就是移动比特就好了。

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0x0;
        uint32_t flag = 0x00000001;
        for (int i = 0; i < 32; ++i) {
            uint32_t tmp = n & (flag << i);
            tmp >>= i;
            result |= (tmp << (31 - i));
        }
        return result;
    }
};
```

还有人用了分治的思想。

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
```
