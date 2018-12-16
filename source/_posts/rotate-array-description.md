---
title: 189. Rotate Array
date: 2018-12-16 17:12:08
tags:
alias: 189/
---

数组移动 k 步。

<!--more-->

我是直接截取插入，然后去除后面部分。

```cpp
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        const auto n = nums.size();
        k %= n;
        nums.insert(nums.begin(), nums.begin() + n - k, nums.end());
        nums.erase(nums.begin() + n, nums.end());
    }
};
```

还有人分成两部分，然后先总体反转，最后两部分也反转。

```cpp
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```
