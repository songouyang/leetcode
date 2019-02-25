---
title: 299. Bulls and Cows
date: 2019-02-25 23:13:49
tags:
alias: 299/
---

判断两个字符串有多少数字位置和大小都相等，以及多少个只是大小相等，位置不相等。

<!--more-->

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        map<char, int> m;
        int A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) ++A;
            m[secret[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (m[guess[i]] > 0) {
                ++B;
                --m[guess[i]];
            }
        }
        return to_string(A) + "A" + to_string(B - A) + "B";
    }
};
```

卧槽，这个厉害了！

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> numbers(10, 0);
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                if (numbers[secret[i] - '0']++ < 0) cows++;
                if (numbers[guess[i] - '0']-- > 0) cows++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```
