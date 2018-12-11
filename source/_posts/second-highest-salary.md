---
title: 176. Second Highest Salary
date: 2018-12-11 20:41:20
tags:
alias: 176/
---

取出数据库中第二高的工资。

<!--more-->

```sql
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (
	SELECT MAX(Salary)
	FROM Employee
);
```

讨论区的高票答案。

```sql
SELECT (
		SELECT DISTINCT Salary
		FROM Employee
		ORDER BY Salary DESC
		LIMIT 1, 1
	) AS SecondHighestSalary;
```

当时很不能理解这样的话就能出来 `NULL`，而我下面的写法就不能。

```sql
SELECT Salary AS SecondHighestSalary
FROM (
	SELECT DISTINCT Salary
	FROM Employee
	ORDER BY Salary DESC
	LIMIT 1, 1
) A;
```

可能是我这样如果没有第二大的话，应该是返回的是个空字符串，而不是 `NULL`。
