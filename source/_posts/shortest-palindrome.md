---
title: 214. Shortest Palindrome
date: 2018-12-25 14:33:49
tags:
alias: 214/
---

在字符串前面补充最少的字符使得它成为回文。

<!--more-->

最简单且最容易想到的就是暴力法。

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        string tmp = s;
        std::reverse(tmp.begin(), tmp.end());
        int n = s.size();
        int i = n;
        while (i > 0) {
            if (tmp.substr(n - i) == s.substr(0, i)) break;
            --i;
        }
        return tmp.substr(0, n - i + 1) + s;
    }
};
```

然后优化的方法就是利用 KMP 的思想，求出 `next` 数组。关于 KMP 可以参考 [KMP 算法的理解与实现](https://www.ouyangsong.com/posts/13016/) 。

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};
```

举个例子，假如输入的字符串 `s` 等于 `a a c e c a a a`，那么 `l` 等于 `a a c e c a a a # a a a c e c a a`，对应的 `next` 数组是 `0 1 0 0 0 1 2 2 0 1 2 2 3 4 5 6 7`，这里只关心最后一个数字 7。因为它说明 `s` 的前 7 个是关于中心对称的。那么只需要把其他不对称的补起来即可。妙！
