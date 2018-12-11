---
title: 175. Combine Two Tables
date: 2018-12-11 20:24:42
tags:
alias: 175/
---

SQL 的左连接查询。

<!--more-->

```sql
SELECT a.FirstName AS FirstName, a.LastName AS LastName, b.City AS City, b.State AS State
FROM Person a
	LEFT JOIN Address b ON a.PersonId = b.PersonId;
```
