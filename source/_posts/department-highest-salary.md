---
title: 184. Department Highest Salary
date: 2018-12-15 16:05:16
tags:
alias: 184/
---

找出每个部门中薪水最高的人。

<!--more-->

使用子查询找到每个部门 ID 对应最高薪。

```sql
SELECT dep.Name AS Department, emp.Name AS Employee, emp.Salary
FROM Department dep, Employee emp
WHERE emp.DepartmentId = dep.Id
	AND emp.Salary = (
		SELECT MAX(Salary)
		FROM Employee e2
		WHERE e2.DepartmentId = dep.Id
	)
```
