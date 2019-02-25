---
title: 289. Game of Life
date: 2019-02-25 13:39:39
tags:
alias: 289/
---

推导出下一次细胞存活的情况。

<!--more-->

给定一个由 0、1 组成的矩阵，每一个元素表示一个细胞的存活，1 存活，0 死亡，其中下一次更新每个细胞的存活由上、下、左、右、左上、左下、右上、右下，八个细胞决定，存活规则如下：

1. 周围存活细胞小于 2 个，则死亡。
2. 周围存活细胞 2 个或 3 个，则存活到下一次更新。
3. 周围存活细胞 3 个以上，则死亡。
4. 周围存活细胞 3 个的死细胞，将会成为一个活细胞。

用两个 bit 来代表两次周期的存活。

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = -board[i][j];
                for (int I = max(0, i - 1); I < min(m, i + 2); ++I) {
                    for (int J = max(0, j - 1); J < min(n, j + 2); ++J) {
                        count += board[I][J] & 1;
                    }
                }

                if (count == 3 || (count == 2 && board[i][j] & 1 == 1)) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
```
