---
title: 181. Employees Earning More Than Their Managers
date: 2018-12-15 15:55:17
tags:
alias: 181/
---

找出赚到比他经理还多的员工。

<!--more-->

对同一个表进行内连接。

```sql
SELECT E1.Name AS Employee
FROM Employee E1, Employee E2
WHERE E1.ManagerId = E2.Id
	AND E1.Salary > E2.Salary
```
