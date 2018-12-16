---
title: 197. Rising Temperature
date: 2018-12-16 20:00:52
tags:
alias: 197/
---

找出温度增长的那一天。

<!--more-->

关键会用 `TO_DAYS` 函数，它返回该天位于今年的多少天。

```sql
SELECT wt1.Id
FROM Weather wt1, Weather wt2
WHERE wt1.Temperature > wt2.Temperature
	AND TO_DAYS(wt1.RecordDate) - TO_DAYS(wt2.RecordDate) = 1;
```
