---
title: 149. Max Points on a Line
date: 2018-12-09 17:55:44
tags:
alias: 149/
---

求平面上共线最多的点的个数。

<!--more-->

对于某个点，计算它和其他点的斜率，并用 `map` 记录下来。关于斜率的话，防止因为浮点数的精度而引起误判，使用分数来代表斜率。还需要注意的地方是就是同一个地方可能有多个点，需要把这些重复的点也要加进来。

```cpp
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int result = 0;
        const auto n = points.size();
        for (int i = 0; i < n; ++i) {
            slopes.clear();
            int duplicate = 0;
            for (int j = i; j < n; ++j) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    ++duplicate;
                } else {
                    int dx = points[j].x - points[i].x;
                    int dy = points[j].y - points[i].y;
                    int dvs = gcd(dx, dy);
                    slopes[{dx / dvs, dy / dvs}]++;
                }
                result = max(result, duplicate);
                for (auto slope:slopes) {
                    result = max(result, duplicate + slope.second);
                }
            }
        }
        return result;
    }

private:
    map<pair<int, int>, int> slopes;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
```
