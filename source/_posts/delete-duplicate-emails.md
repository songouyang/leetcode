---
title: 196. Delete Duplicate Emails
date: 2018-12-16 19:58:10
tags:
alias: 196/
---

删除重复的邮件的字段。

<!--more-->

这个思路之前使用过，就是用两个表判断 ID 的大小。

```sql
DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email
	AND p1.Id > p2.Id
```
