---
title: 146. LRU Cache
date: 2018-12-09 16:12:34
tags:
alias: 146/
---

实现 LRU 缓存。LRU 的机制就是淘汰不常用的，而常用的不断缓存住。如果达到了容量，就把最不常用的淘汰了。

<!--more-->

题目要求时间复杂度是 `O(1)`，所以需要用 `map` 减少查询的时间复杂度。用一个 `list` 来描述淘汰机制，如果查询了或者插入的时候，将 `key` 提到最前面。如果到了容量就把最后的一个元素删除了。之所以在 `list` 要把 `key` 和 `value` 都缓存住，因为删除的时候需要反查出 `kye`，然后在 `map` 中删除。查询的时候则是需要使用 `list` 中的 `value`。

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }

    int get(int key) {
        if (mp.count(key) <= 0) {
            return -1;
        }
        auto position = mp[key];
        auto result = *position;
        lru_queue.erase(position);
        lru_queue.push_front(result);
        mp[key] = lru_queue.begin();
        return result.second;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            mp[key]->second = value;
            return;
        }
        lru_queue.push_front({key, value});
        mp[key] = lru_queue.begin();
        while (lru_queue.size() > _cap) {
            mp.erase(lru_queue.back().first);
            lru_queue.pop_back();
        }
    }

private:
    int _cap = 0;
    list<pair<int, int>> lru_queue;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};
```
