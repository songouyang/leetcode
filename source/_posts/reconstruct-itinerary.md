---
title: 332. Reconstruct Itinerary
date: 2019-03-08 11:12:50
tags:
alias: 332/
---

根据机票重构出飞行路线。

<!--more-->

遇到可行的几种方案，需要按照字典排序。

```cpp
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket: tickets) {
            routes[ticket.first].insert(ticket.second);
        }
        helper("JFK");
        reverse(result.begin(), result.end());
        return result;
    }

private:
    map<string, multiset<string>> routes;
    vector<string> result;

    void helper(string start) {
        while (routes[start].size()) {
            auto tmp = *routes[start].begin();
            routes[start].erase(routes[start].begin());
            helper(tmp);
        }
        result.push_back(start);
    }
};
```
