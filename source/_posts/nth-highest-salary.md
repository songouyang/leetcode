---
title: 177. Nth Highest Salary
date: 2018-12-11 20:58:49
tags:
alias: 177/
---

取出数据库中第 N 高的工资。

<!--more-->

把 [176. Second Highest Salary](https://songouyang.github.io/leetcode/second-highest-salary/) 中的 `1` 改成 `N-1` 即可。

```sql
CREATE FUNCTION getNthHighestSalary (
	N INT
)
RETURNS INT
BEGIN
	SET N = N - 1;
	RETURN (SELECT (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT N, 1) AS second);
END
```

讨论区还有一种思路就是求出排在某工资上的个数等于 `N-1` 的。

```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN RETURN
  ( # Write your MySQL query statement below.
 SELECT e1.Salary
   FROM
     (SELECT DISTINCT Salary
      FROM Employee) e1
   WHERE
       (SELECT COUNT(*)
        FROM
          (SELECT DISTINCT Salary
           FROM Employee) e2
        WHERE e2.Salary > e1.Salary) = N - 1
   LIMIT 1 ); END
```
