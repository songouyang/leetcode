---
title: 262. Trips and Users
date: 2019-02-22 16:51:59
tags:
alias: 262/
---

求订单取消率。

<!--more-->

```sql
SELECT Request_at AS Day
	, round(COUNT(if(Status != 'completed', true, NULL)) / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
WHERE Request_at BETWEEN '2013-10-01' AND '2013-10-03'
	AND Client_Id NOT IN (
		SELECT Users_Id
		FROM Users
		WHERE Banned = 'Yes'
	)
GROUP BY Request_at;
```
