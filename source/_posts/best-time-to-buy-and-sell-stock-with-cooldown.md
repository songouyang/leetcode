---
title: 309. Best Time to Buy and Sell Stock with Cooldown
date: 2019-02-28 17:15:34
tags:
alias: 309/
---

带有冷冻期的买卖股票问题。卖完股票后需要等待一天才能继续买股票。

<!--more-->

当前卖的最高价格等于前一天卖的最高价格和昨天买今天卖的利润的最高值；
当前买的最高价格等于前一天买的最高价格和前天卖昨天买的利润的最高值；

其中 `pre_sell` 用来表示前天卖完后的利润。

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int pre_sell = 0, now_sell = 0, buy = -prices[0];
        for (const auto price: prices) {
            int tmp = now_sell;
            now_sell = max(now_sell, price + buy);
            buy = max(buy, pre_sell - price);
            pre_sell = tmp;
        }
        return now_sell;
    }
};
```
