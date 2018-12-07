---
title: 130. Surrounded Regions
date: 2018-12-06 21:43:14
tags:
alias: 130/
---

将被包围了 `O` 全部替换成 `X`，但是边缘上的 `O` 不算成被包围的。

<!--more-->

找到四边的 `O`，然后 DFS 找到相连接的 `O`，并把它们替换成 `$`。最后重新全部遍历一次二维数组，把所有剩下的 `O` 替换成 `X`，把 `$` 替换成 `O` 即可。

```cpp
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        const auto m = board.size();
        const auto n = board[0].size();
        for (int i = 0; i < m; ++i) {
            helper(i, 0, board);
            helper(i, n - 1, board);
        }
        for (int i = 0; i < n; ++i) {
            helper(0, i, board);
            helper(m - 1, i, board);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '$') {
                    board[i][j] = 'O';
                } else if (board[i][j] = 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void helper(int i, int j, vector<vector<char>> &board) {
        if (i >= 0 && j >= 0 && i < board.size() && j < board[i].size() && board[i][j] == 'O') {
            board[i][j] = '$';
            helper(i + 1, j, board);
            helper(i - 1, j, board);
            helper(i, j + 1, board);
            helper(i, j - 1, board);
        }
    }
};
```
