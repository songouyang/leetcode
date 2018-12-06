---
title: 121. Best Time to Buy and Sell Stock
date: 2018-12-06 12:11:17
tags:
alias: 121/
---

分别有一次买和卖的机会，求最大利益是多少。

<!--more-->

用 `result` 表示目前能获利的最大利益。`tmp` 表示本轮买卖还是否在获利，`tmp` 是本轮买卖的利益的累加。如果 `tmp` 小于 0，说明这轮是亏的，应该重新计算，也就是从当前再开始买股票。

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        int tmp = 0;
        const int m = prices.size();
        for (int i = 1; i < m; ++i) {
            tmp = max(prices[i] - prices[i - 1] + tmp, 0);
            result = max(result, tmp);
        }
        return result;
    }
};
```

还有一种思路就是求出之前的最小的价格，以及求出之前的利益最大值。

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};
```
