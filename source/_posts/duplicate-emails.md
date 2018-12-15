---
title: 182. Duplicate Emails
date: 2018-12-15 15:58:56
tags:
alias: 182/
---

找出重复的电子邮箱。

<!--more-->

邮箱相同，但是 ID 不等于的时候就说明有重复。

```sql
SELECT DISTINCT t1.Email
FROM Person t1
	JOIN Person t2
	ON t1.email = t2.email
		AND t1.id <> t2.id
```
