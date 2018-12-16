---
title: 202. Happy Number
date: 2018-12-16 23:45:47
tags:
alias: 202/
---

判断一个数字是不是开心数字。

<!--more-->

按照题目要求不断计算即可，如果出现循环并且不是等于 1，那么就说明不是开心数字。

```cpp
class Solution {
public:
    bool isHappy(int n) {
        while (true) {
            n = helper(n);
            if (n == 1) {
                return true;
            } else if (_s.count(n)) {
                return false;
            } else {
                _s.insert(n);
            }
        }
    }

    int helper(int n) {
        int result = 0;
        while (n) {
            result += pow(n % 10, 2);
            n = n / 10;
        }
        return result;
    }

private:
    unordered_set<int> _s;
};
```

讨论区还有人利用快慢指针的思想。

```cpp
class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while (slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }
};
```
