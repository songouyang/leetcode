---
title: 180. Consecutive Numbers
date: 2018-12-15 15:50:18
tags:
alias: 180/
---

选择连续出现 3 次的数字。

<!--more-->

用 `count` 来计数，用 `record` 记录上次的数字。

```sql
SELECT DISTINCT num AS consecutivenums
FROM (
	SELECT num
		, CASE 
			WHEN @record = num THEN @count := @count + 1
			WHEN @record := num THEN @count := 1
		END AS n
	FROM logs, (
			SELECT @count := 0, @record := NULL
		) r
) a
WHERE a.n >= 3;
```
