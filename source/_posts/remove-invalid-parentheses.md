---
title: 301. Remove Invalid Parentheses
date: 2019-02-26 15:39:48
tags:
alias: 301/
---

移除多余的括号，使得字符串里面的括号是符合表达式的。

<!--more-->

用两个变量分别记录左右括号的个数。如果两个都等于 0，并且字符串是符合规范的，那么就加入结果中。如果左括号更多，并且当前的字符就是左括号，那么移除该字符并递归。同理右括号也是这样。需要注意的是如果相邻两个都是相同的括号，只移除最后一个来进行判断，否则增加了无谓的运算。

```cpp
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        int cnt1 = 0, cnt2 = 0;
        for (char c: s) {
            cnt1 += c == '(';
            if (cnt1 == 0) {
                cnt2 += c == ')';
            } else {
                cnt1 -= c == ')';
            }
        }
        helper(s, 0, cnt1, cnt2, result);
        return result;
    }

private:
    void helper(string s, int i, int cnt1, int cnt2, vector<string> &result) {
        if (cnt1 == 0 && cnt2 == 0 && isValid(s)) {
            result.push_back(s);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (j != i && s[j] == s[j - 1]) continue;
            if (cnt1 > 0 and s[j] == '(') {
                helper(s.substr(0, j) + s.substr(j + 1), j, cnt1 - 1, cnt2, result);
            }
            if (cnt2 > 0 and s[j] == ')') {
                helper(s.substr(0, j) + s.substr(j + 1), j, cnt1, cnt2 - 1, result);
            }
        }
    }

    bool isValid(string s) {
        int tmp = 0;
        for (char c : s) {
            if (c == '(') {
                tmp++;
            } else if (c == ')' && --tmp < 0) {
                return false;
            }
        }
        return tmp == 0;
    }
};
```

讨论区的高赞解法。首先是删除多余的右括号，发现有多余的右括号就进入第二个循环，并递归。然后对左括号多的情况进行处理，把字符串反转一下，进行同样的操作。最后再把符合条件的字符串加入到结果中。（实际上因为有个压栈与出栈的原因，结果中是先把左括号多的情况加入结果中。）

```cpp
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(res, s, ')', 0);
        return res;
    }

    void dfs(vector<string> &res, string s, char c, int start) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                s[i] == c ? cnt++ : cnt--;
            }
            if (cnt <= 0)continue;
            for (int j = start; j <= i; j++) {
                if (s[j] == c && (j == start || s[j - 1] != s[j]))
                    dfs(res, s.substr(0, j) + s.substr(j + 1), c, j);
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (c == ')')
            return dfs(res, s, '(', 0);
        res.push_back(s);
    }
};
```

感觉这个想法很难想出来。
