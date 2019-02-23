---
title: 273. Integer to English Words
date: 2019-02-23 19:19:15
tags:
alias: 273/
---

将数字转化为英文表示。

<!--more-->

主要是需要知道一个数字转换的过程需要进行分级。分别是「千」，「百万」，「十亿」。每 3 位就是一级。每个级别之内就是简单的「个十百」来组成。

```cpp
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string result;
        int i = 0;
        while (num) {
            if (num % 1000) result = helper(num % 1000) + thousands[i] + (result.empty() ? result : " " + result);
            num /= 1000;
            ++i;
        }
        return result;
    }

    string helper(int num) {
        if (num < 20) {
            return ones[num];
        } else if (num < 100) {
            return tens[num / 10] + (ones[num % 10].empty() ? "" : " " + ones[num % 10]);
        } else if (num < 1000) {
            return ones[num / 100] + " Hundred" + (helper(num % 100).empty() ? "" : " " + helper(num % 100));
        }
        return "";
    }

private:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                           "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", " Thousand", " Million", " Billion"};
};
```

我主要花了一些时间调整空格。后来发现别人处理的比我好。

```cpp
class Solution {
public:
    static string numberToWords(int num) {
        if (num == 0) return "Zero";
        bool is_negative = num < 0;
        if (is_negative)
            num = abs(num);
        string ans = int_to_string(num);
        return (is_negative ? "Negative " : "") + ans.substr(1);
    }

private:
    static string int_to_string(int num) {
        if (num >= 1000000000) {
            return int_to_string(num / 1000000000) + " Billion" + int_to_string(num % 1000000000);
        } else if (num >= 1000000) {
            return int_to_string(num / 1000000) + " Million" + int_to_string(num % 1000000);
        } else if (num >= 1000) {
            return int_to_string(num / 1000) + " Thousand" + int_to_string(num % 1000);
        } else if (num >= 100) {
            return int_to_string(num / 100) + " Hundred" + int_to_string(num % 100);
        } else if (num >= 20) {
            return string(" ") + below_100[(num - 20) / 10] + int_to_string(num % 10);
        } else if (num > 0) {
            return string(" ") + below_20[num - 1];
        } else
            return "";
    }

    static const char *below_20[];
    static const char *below_100[];
};

const char *Solution::below_20[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                    "Eighteen", "Nineteen"};
const char *Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
```
