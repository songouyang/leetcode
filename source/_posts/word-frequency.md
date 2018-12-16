---
title: 192. Word Frequency
date: 2018-12-16 18:52:52
tags:
alias: 192/
---

对词频进行排序。

<!--more-->

```sh
for i in `cat words.txt` ; do echo $i ; done | sort | uniq -c | sort -nr | awk '{print $2, $1}'
```
