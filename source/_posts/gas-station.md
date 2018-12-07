---
title: 134. Gas Station
date: 2018-12-07 15:35:15
tags:
alias: 134/
---

有一圈的加油站，并且加油站之间的路程还需要消耗汽油，问从哪个加油站开始出发，可以完整的走完一圈。

<!--more-->

我一开始的想法就是直接一个一个加油站的尝试，从某个加油站开始，往下走并计算车上还多少油，如果小于 0，说明这个起点不对。如果回到了起点说明这个起点加油站可以了。

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        const auto m = gas.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0, sum = 0; j <= m; ++j) {
                int index = (i + j) % m;
                sum += gas[index] - cost[index];
                if (sum < 0) {
                    break;
                } else if (j == m) {
                    return i;
                }
            }
        }
        return -1;
    }
};
```

这样的话时间复杂度是 `O(n^2)`，所以时间排名很靠后。其实是可以优化到 `O(n)` 的。

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        const auto m = gas.size();
        int total = 0;
        int sum = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                index = i + 1;
            }
        }
        return total >= 0 ? index : -1;
    }
};
```
`total` 是表示总的补充和消耗的，如果它小于 0，肯定不存在这样的点让你完成一圈，如果它大于 0，肯定存在这样一个点让你完成一圈的。
`sum` 的话表示某一段的补充和消耗的，如果它小于 0，那么这一段的点都是不能成为出发点的。举个例子从 `i` 到 `j`，因为在这一段中间，汽车的油都是大于 0 的，如果你以中间某个点 `k` 开始，那么之前都不能到的 `j` 点，现在更不能到了，因为从 `i` 到 `k` 对于汽车来说油肯定不会少的。如果从 `k` 出发，相当于减去了一个非负数，那么到了 `j` 点的 `sum` 一定更小了。

当然还看到另外一种思路。如果 `sum` 大于 0，说明汽车还能走的更远，那么把终点移远一点。如果 `sum` 小于 0，那么把起点往前移动，尝试多加一点油出发。如果最后 `sum` 大于 0，说明总的补充大于消耗，是可以完成一圈的。

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int start = gas.size() - 1;
        int end = 0;
        int sum = gas[start] - cost[start];
        while (start > end) {
            if (sum >= 0) {
                sum += gas[end] - cost[end];
                ++end;
            } else {
                --start;
                sum += gas[start] - cost[start];
            }
        }
        return sum >= 0 ? start : -1;
    }
};
```
