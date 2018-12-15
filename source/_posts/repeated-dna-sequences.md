---
title: 187. Repeated DNA Sequences
date: 2018-12-15 17:11:22
tags:
alias: 187/
---

找出重复的 DNS 片段。

<!--more-->

第一眼的想法就是把每个片段都存到 `set` 中，然后判断之前是否出现过。如果出现过就添加到结果中。

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        for (int i = 0; i + 9 < s.size(); ++i) {
            string tmp = s.substr(i, 10);
            if (_all.count(tmp)) {
                _result.insert(tmp);
            } else {
                _all.insert(tmp);
            }
        }
        vector<string> result(_result.begin(), _result.end());
        return result;
    }

private:
    std::set<string> _all;
    std::set<string> _result;
};
```

讨论区还有一种做法是利用比特，将 10 位的字符串映射成一个整数，然后判断这个数字有没有出现过。

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set <string> res;
        unordered_set<int> st;
        unordered_map<int, int> m{{'A', 0},
                                  {'C', 1},
                                  {'G', 2},
                                  {'T', 3}};
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 2 | m[s[i++]];
        while (i < s.size()) {
            cur = ((cur & 0x3ffff) << 2) | (m[s[i++]]);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};
```
