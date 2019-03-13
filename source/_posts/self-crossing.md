---
title: 335. Self Crossing
date: 2019-03-13 13:21:24
tags:
alias: 335/
---

判断走位会不会自己相交。

<!--more-->

相交的情况一共分成 3 种。

```
    x(1)
    ┌───┐
x(2)│   │x(0)
    └───┼──>
    x(3)│
```

```
      x(1)
    ┌──────┐
    │      │x(0)
x(2)│      ^
    │      │x(4)
    └──────│
      x(3)
```

```
      x(1)
    ┌──────┐
    │      │x(0)
x(2)│     <│────│
    │       x(5)│x(4)
    └───────────│
        x(3)
```

对应的代码的三种判断。

```cpp
class Solution {
public:
    bool isSelfCrossing(vector<int> &x) {
        for (int i = 3; i < x.size(); ++i) {
            if (x[i] >= x[i - 2] && x[i - 1] >= x[i - 3])return true;
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] >= x[i - 2] - x[i - 4]) return true;
            if (i >= 5 && x[i - 2] >= x[i - 4] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i] >= x[i - 2] - x[i - 4] &&
                x[i - 3] >= x[i - 1])
                return true;

        }
        return false;
    }
};
```
