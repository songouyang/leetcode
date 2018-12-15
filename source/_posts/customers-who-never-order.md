---
title: 183. Customers Who Never Order
date: 2018-12-15 16:01:48
tags:
alias: 183/
---

找出没有购买记录的客户。

<!--more-->

左连接之后，订单号不是 `NULL` 就说明有购买记录。

```sql
SELECT Name AS Customers
FROM Customers
	LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;
```
