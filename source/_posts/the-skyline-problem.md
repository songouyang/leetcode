---
title: 218. The Skyline Problem
date: 2019-01-17 18:50:36
tags:
alias: 218/
---

用点描绘建筑的边框。

<!--more-->

![](https://wx1.sinaimg.cn/large/e2a28cd6ly1fz9s02y7qxj20q20kxq30.jpg)

![](https://wx4.sinaimg.cn/large/e2a28cd6ly1fz9s0jjskzj20q20kx3yo.jpg)

主要需要描绘的点是水平线段的左边的点。
首先对所有顶点进行排序，因为后面需要依次遍历所有顶点。
- 优先按照 `x` 的大小。
- 当 `x` 相等的时候，先遍历是左顶点的。
- 当 `x` 相等的时候，且都是左顶点的时候，先遍历 `y` 更大的。
- 当 `x` 相等的时候，且都是右顶点的时候，先遍历 `y` 更小的。

使用 `pre` 记录当前最高的值，使用 `multiset` 红黑树用来记录当前有效的高度并且找出其中最大值。

- 如果是左顶点，将当前高度加入 `multiset` 中。
- 如果是右顶点，那么将 `multiset` 中的当前高度的顶点（包括该右顶点对应的左顶点）去除。

如果最大高度发生了改变，说明有了转折点。需要在此时添加顶点了，如果是左顶点的话就直接添加了。如果是右顶点，待加入的点的横坐标是当前的横坐标，纵坐标是当前记录有效的最高的记录。

```cpp
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> nodes, result;
        for (auto &building: buildings) {
            nodes.emplace_back(building[0], -building[2]);
            nodes.emplace_back(building[1], building[2]);
        }
        sort(nodes.begin(), nodes.end());
        multiset<int> heights;
        int pre = 0, cur = 0;
        heights.insert(0);
        for (auto &node: nodes) {
            if (node.second < 0) {
                heights.insert(-node.second);
            } else {
                heights.erase(heights.find(node.second));
            }
            cur = *(heights.rbegin());
            if (pre != cur) {
                result.emplace_back(node.first, cur);
                pre = cur;
            }
        }
        return result;
    }
};
```

本题参考的链接：

- <https://www.cnblogs.com/Jueis-lishuang/p/5006051.html>
- <https://blog.csdn.net/qq_36153312/article/details/81951615>
