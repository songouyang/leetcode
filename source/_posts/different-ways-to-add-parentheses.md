---
title: 241. Different Ways to Add Parentheses
date: 2019-02-21 11:01:46
tags:
alias: 241/
---

给字符串加括号，求出所有能得到的运算结果。

<!--more-->

这是组合数学中的 [卡塔兰数](https://zh.wikipedia.org/zh-hans/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0)。通过运算符把字符串分割开来。

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int n = input.size();
        for (int i = 0; i < n; ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> result1, result2;
                string str1 = input.substr(0, i);
                string str2 = input.substr(i + 1);
                if (umap.find(str1) == umap.end()) {
                    result1 = diffWaysToCompute(str1);
                } else {
                    result1 = umap[str1];
                }
                if (umap.find(str2) == umap.end()) {
                    result2 = diffWaysToCompute(str2);
                } else {
                    result2 = umap[str2];
                }
                for (auto it1: result1) {
                    for (auto it2: result2) {
                        if (c == '+') {
                            result.push_back(it1 + it2);
                        } else if (c == '-') {
                            result.push_back(it1 - it2);
                        } else if (c == '*') {
                            result.push_back(it1 * it2);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        umap[input] = result;
        return result;
    }

private:
    unordered_map<string, vector<int>> umap;
};
```
