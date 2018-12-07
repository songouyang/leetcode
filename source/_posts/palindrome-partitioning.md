---
title: 131. Palindrome Partitioning
date: 2018-12-07 13:33:12
tags:
alias: 131/
---

将字符串切分开来，保证每个分段都是回文。

<!--more-->

使用 DFS 回溯即可，判断下一个分片是不是回文，如果是回文就进入下一层。

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        helper(s, tmp, 0);
        return result;
    }

    void helper(string s, vector<string> &tmp, int start) {
        if (start == s.size()) {
            result.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (is_palindrome(s, start, i)) {
                tmp.push_back(s.substr(start, i - start + 1));
                helper(s, tmp, i + 1);
                tmp.pop_back();
            }
        }
    }

    bool is_palindrome(string s, int left, int right) {
        if (left == right) {
            return true;
        }
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }

private:
    vector<vector<string>> result;
};
```
