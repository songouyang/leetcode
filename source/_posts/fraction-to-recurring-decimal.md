---
title: 166. Fraction to Recurring Decimal
date: 2018-12-11 11:59:48
tags:
alias: 166/
---

将分数转化为小数。如果由循环的需要用括号表示。

<!--more-->

所谓重复，其实就是被除数出现了重复，这样的话就会进入一个不断除以的死循环。那么只要把所有被除数都记录下来，并且记录它对应的出现的开始的位置。一旦发现有一样的被除数，就加上括号结束循环。

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)return "0";
        string result;
        int64_t n = numerator, d = denominator;
        if (n < 0 ^ d < 0)result += "-";
        n = abs(n), d = abs(d);
        result += to_string(n / d);
        int64_t r = n % d;
        if (r == 0) {
            return result;
        } else {
            result += ".";
        }
        unordered_map<int64_t, unsigned long> mp;
        for (; r != 0; r %= d) {
            if (mp.count(r)) {
                result.insert(mp[r], 1, '(');
                result += ")";
                break;
            }
            mp[r] = result.size();
            r *= 10;
            result += to_string(r / d);
        }
        return result;
    }
};
```
