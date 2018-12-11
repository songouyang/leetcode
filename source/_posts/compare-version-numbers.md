---
title: 165. Compare Version Numbers
date: 2018-12-11 11:04:37
tags:
alias: 165/
---

比较版本号的大小。

<!--more-->

现将字符串切分成数组，然后把数组中的每个字符串的左边的 0 去除。接下来逐个比较每个字符串对应的数值的大小。

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = str2vec(version1);
        auto v2 = str2vec(version2);
        auto max_length = max(v1.size(), v2.size());
        for (int i = 0; i < max_length; ++i) {
            string s1 = i < v1.size() ? v1[i] : "0";
            string s2 = i < v2.size() ? v2[i] : "0";
            lstrip(s1);
            lstrip(s2);
            if (s1.size() == s2.size()) {
                for (int j = 0; j < s1.size(); ++j) {
                    if (s1[j] == s2[j])continue;
                    return s1[j] > s2[j] ? 1 : -1;
                }
            } else {
                return s1.size() > s2.size() ? 1 : -1;
            }
        }
        return 0;
    }

private:
    vector<string> str2vec(const string &s) {
        string tmp = s;
        vector<string> result;
        while (true) {
            auto loc = tmp.find('.');
            if (loc != string::npos) {
                result.push_back(tmp.substr(0, tmp.find('.')));
                tmp = tmp.substr(tmp.find('.') + 1);
            } else {
                result.push_back(tmp);
                break;
            }
        }
        return result;
    }

    void lstrip(string &s) {
        auto i = 0UL;
        while (i < s.size() && s[i] == '0') {
            ++i;
        }
        s = s.substr(i);
    }
};
```
