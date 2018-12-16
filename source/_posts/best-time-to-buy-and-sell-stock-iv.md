---
title: 188. Best Time to Buy and Sell Stock IV
date: 2018-12-16 16:48:33
tags:
alias: 188/
---

可以买卖最多 `k`，如何获利最大。

<!--more-->

使用两个数组 `local` 和 `global` 分别表示局部最高和全局最高。`local[i][j]` 表示在第 `i` 天交易了第 `j` 次，其中第 `j` 次必须在这一天出手。`global[i][j]` 表示在 `i` 天内交易 `j` 次可以获得的最高利益。需要注意的是可以在同一天内买入和卖出。

递推关系如下：

```cpp
local[i][j] = max(global[i - 1][j - 1] + max(prices[i] - prices[i-1], 0),
                  local[i - 1][j] + prices[i] - prices[i-1]);
glocal[i][j] = max(local[i][j], glocal[i - 1][j]);
```

可以优化空间复杂度，将二维空间优化成一维空间。

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        const auto n = prices.size();
        int result = 0;
        if (n == 0)return result;
        if (k > n) {
            for (int i = 1; i < n; ++i) {
                result += max(0, prices[i] - prices[i - 1]);
            }
            return result;
        }
        int local[k + 1] = {0};
        int global[k + 1] = {0};
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j > 0; --j) {
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
};
```

这里还有优化的地方就是当 `k` 大于 `n` 的时候其实就相当于无限制的交易了。所以当 `k` 大于 `n` 的时候可以另外计算了。
