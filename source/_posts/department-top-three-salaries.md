---
title: 185. Department Top Three Salaries
date: 2018-12-15 16:39:19
tags:
alias: 185/
---

找出每个部门薪水前三的。

<!--more-->

前三的话以为排在他前面的不能超过 0、1、2 个人。

```sql
SELECT d.Name AS Department, e.Name AS Employee, e.Salary
FROM Employee e
	JOIN Department d ON e.DepartmentId = d.Id
WHERE (
	SELECT COUNT(DISTINCT Salary)
	FROM Employee
	WHERE Salary > e.Salary
		AND DepartmentId = d.Id
) < 3
ORDER BY d.Name, e.Salary DESC;
```

还有就是添加排名，这个思路和之前 [180. Consecutive Numbers](https://songouyang.github.io/leetcode/consecutive-numbers/) 类似。

```sql
SELECT d.Name AS Department, e.Name AS Employee, e.Salary
FROM (
	SELECT Name, Salary, DepartmentId
		, @rank := IF(@pre_d = DepartmentId, @rank + (@pre_s <> Salary), 1) AS rank
		, @pre_d := DepartmentId, @pre_s := Salary
	FROM Employee, (
			SELECT @pre_d := -1, @pre_s := -1
				, @rank := 1
		) init
	ORDER BY DepartmentId, Salary DESC
) e
	JOIN Department d ON e.DepartmentId = d.Id
WHERE e.rank <= 3
ORDER BY d.Name, e.Salary DESC;
```
