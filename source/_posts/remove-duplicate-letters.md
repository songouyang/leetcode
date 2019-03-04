---
title: 316. Remove Duplicate Letters
date: 2019-03-04 15:24:43
tags:
alias: 316/
---

求出字符串中所有的不重复的字母，按照字典的排序输出，并且保持原有的相对位置不变。

<!--more-->

所谓字典顺序就是能有 `abc` 就不用 `bca`，因为这样的话 `a` 排在更前面。

这里的最优解是使用栈，并且根据后面还是否会再出现来决定是否需要 `pop` 操作。

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(26, 0);
        for (char c: s) {
            hash[c - 'a']++;
        }
        vector<bool> visited(26, 0);
        string result;
        for (char c: s) {
            hash[c - 'a']--;
            if (visited[c - 'a']) continue;
            while (!result.empty() && c < result.back() && hash[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += c;
            visited[c - 'a'] = true;
        }
        return result;
    }
};
```

`visited` 数组是记录目前结果字符串中已经包含的字母，`hash` 数组记录每个字母出现的次数，决定了是否需要 `pop`。
