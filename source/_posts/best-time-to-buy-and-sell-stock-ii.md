---
title: 122. Best Time to Buy and Sell Stock II
date: 2018-12-06 12:52:53
tags:
alias: 122/
---

和 [121. Best Time to Buy and Sell Stock](/best-time-to-buy-and-sell-stock/) 题的区别就是这里可以无限次买卖。

<!--more-->

只需要把 [121. Best Time to Buy and Sell Stock](/best-time-to-buy-and-sell-stock/) 题的答案稍微修改一下，这次的话 `tmp` 只要不是小于 0，也就是不亏的话，就计算一次 `result` 的大小。`result` 的话判断是否加上这次买卖可以获利更多。

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        int tmp = 0;
        const int m = prices.size();
        for (int i = 1; i < m; ++i) {
            tmp = max(prices[i] - prices[i - 1], 0);
            result = max(result, tmp + result);
        }
        return result;
    }
};
```
