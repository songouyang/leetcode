---
title: 123. Best Time to Buy and Sell Stock III
date: 2018-12-06 14:18:19
tags:
alias: 123/
---

这里要求最多交易两次，也就是最多两次买和卖。

<!--more-->

把数组分成两半，然后求出每一半的最大利益。最后把所有切分方法中，求出两半加起来的利益最大的和即可。

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        int result = 0;
        if (n < 2) {
            return 0;
        }
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        for (int i = 0, flag = prices[0]; i < n; ++i) {
            flag = min(prices[i], flag);
            dp1[i] = max(dp1[i - 1], prices[i] - flag);
        }
        for (int i = n - 2, flag = prices[n - 1]; i >= 0; --i) {
            flag = max(prices[i], flag);
            dp2[i] = max(dp2[i + 1], flag - prices[i]);
        }
        for (int i = 0; i < n; ++i) {
            result = max(result, dp1[i] + dp2[i]);
        }
        return result;
    }
};
```

求左边的最大利益的时候和 [121. Best Time to Buy and Sell Stock](https://songouyang.github.io/leetcode/best-time-to-buy-and-sell-stock/) 一样，但是右边的最大利益求法需要反过来，`flag` 是最高的出价而不再是最低入价了。

分享一下高分答案，只需要遍历一次数组就可以了。

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        auto buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
        for (auto p : prices) {
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1 + p);
            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return sell2;
    }
};
```

它的思路就是认为买就是负数，卖就是正数。这样的话，`buy1` 取最大就是说明得到第一次买的最低买入价格，`sell1` 的话就是以当前的价格卖出去，并且要抛去成本。第二次类似，但是这样的写法保证了不会有交叉，也就是买第二次的时候不能还继续拥有第一次的股票。
