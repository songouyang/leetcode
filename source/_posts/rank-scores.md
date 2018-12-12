---
title: 178. Rank Scores
date: 2018-12-12 15:51:08
tags:
alias: 178/
---

计算出每个成绩的排名，要求如果分数相同那么排名也要一样。

<!--more-->

这一题我是看了讨论区才学会的。

## 思路一

计算有多少比当前分数更高的分数。

```sql
SELECT Score
	, (
		SELECT COUNT(DISTINCT Score)
		FROM Scores
		WHERE Score >= s.Score
	) AS Rank
FROM Scores s
ORDER BY Score DESC;
```
## 思路二

和思路一类似的想法。

```sql
SELECT Score
	, (
		SELECT COUNT(*)
		FROM (
			SELECT DISTINCT Score AS s
			FROM Scores
		) t
		WHERE s >= Score
	) AS Rank
FROM Scores
ORDER BY Score DESC;
```

## 思路三

采用内连接，其中 `t` 表相当于是去重复后的分数，然后 `s` 表用来计算排名。

```sql
SELECT s.Score, COUNT(DISTINCT t.Score) AS Rank
FROM Scores s
	JOIN Scores t ON s.Score <= t.Score
GROUP BY s.Id
ORDER BY s.Score DESC;
```
## 思路四

`pre` 是前一名的分数，如果当前分数和之前的分数不相同就返回 `true`，相等的话就返回 `false`。如果是 `true`，那么 `rank` 就会加 1，否则就是加 0。

```sql
SELECT Score
	, @rank := @rank + (@pre <> (@pre := Score)) AS Rank
FROM Scores, (
		SELECT @rank := 0, @pre := -1
	) INIT
ORDER BY Score DESC;
```

我还没写过这么复杂的 `SQL` 语句。 
