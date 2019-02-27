---
title: 307. Range Sum Query - Mutable
date: 2019-02-27 15:26:47
tags:
alias: 307/
---

求数组中某个范围内的元素之和。该数组是可以通过 `update` 改变元素的。

<!--more-->

暴力法，不解释，只能超过不到 20% 的提交。主要的问题就是如果数组很大，每次 `update` 要修改很多次。

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        origin = nums;
        dp = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            dp[i + 1] = dp[i] + nums[i];
        }
    }

    void update(int i, int val) {
        int diff = val - origin[i];
        for (int j = i; j + 1 < dp.size(); ++j) {
            dp[j + 1] += diff;
        }
        origin[i] = val;
    }

    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }

private:
    vector<int> dp;
    vector<int> origin;
};
```

然后是利用区域分块的思想。把整个数组分成若干个均等的块，每个块记录了当前下标范围内的和。更新的话就更新整个块的值。求范围的和，判断是不是跨越了块，如果没有的话，直接就求和；否则就是把中间的块加起来。

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        if (nums.empty()) return;
        data = nums;
        double root = sqrt(data.size());
        len = ceil(data.size() / root);
        block.resize(len);
        for (int i = 0; i < data.size(); ++i) {
            block[i / len] += data[i];
        }
    }

    void update(int i, int val) {
        int idx = i / len;
        block[idx] += val - data[i];
        data[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        int start = i / len, end = j / len;
        if (start == end) {
            for (int k = i; k <= j; ++k) {
                sum += data[k];
            }
            return sum;
        }
        for (int k = i; k < (start + 1) * len; ++k) {
            sum += data[k];
        }
        for (int k = start + 1; k < end; ++k) {
            sum += block[k];
        }
        for (int k = end * len; k <= j; ++k) {
            sum += data[k];
        }
        return sum;
    }

private:
    int len;
    vector<int> data, block;
};
```

同样是分块的思想，使用了树状数组。需要注意的地方就是求出最低位的方法 `j&(-j)` 以及求范围和的时候。

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        data.resize(nums.size());
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - data[i];
        for (int j = i + 1; j < bit.size(); j += (j & -j)) {
            bit[j] += diff;
        }
        data[i] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }

    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j & -j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> data, bit;
};
```

还有使用线段树的方法，线段树更新的时候只需要更新祖先，不用更新所有的。是不是很像一个堆排序的构建堆。

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        tree.resize(n * 2);
        buildTree(nums);
    }

    void buildTree(vector<int> &nums) {
        for (int i = n; i < n * 2; ++i) {
            tree[i] = nums[i - n];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    void update(int i, int val) {
        tree[i += n] = val;
        while (i > 0) {
            tree[i / 2] = tree[i] + tree[i ^ 1];
            i /= 2;
        }
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (i += n, j += n; i <= j; i /= 2, j /= 2) {
            if ((i & 1) == 1) sum += tree[i++];
            if ((j & 1) == 0) sum += tree[j--];
        }
        return sum;
    }

private:
    int n;
    vector<int> tree;
};
```

主要注意看下求和的函数，该函数是 `i` 和 `j` 都等于 0，然后 `j` 再减去一就终止了，因为 `tree[0]` 等于 0，所以多加上 `tree[0]` 也没有关系的。
