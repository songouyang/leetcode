---
title: 217. Contains Duplicate
date: 2019-01-02 19:54:49
tags:
alias: 217/
---

判断数组是否存在重复的元素。

<!--more-->

用 `set` 去重复即可。

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (const auto &num: nums) {
            if (s.count(num)) {
                return true;
            } else {
                s.insert(num);
            }
        }
        return false;
    }
};
```
