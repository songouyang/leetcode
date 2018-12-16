---
title: 195. Tenth Line
date: 2018-12-16 19:52:11
tags:
alias: 195/
---

打印第 10 行。

<!--more-->

最简单的应该是用 `sed` 了。

```sh
sed -n 10p file.txt
```

然后是用 `tail` 和 `head` 了。

```sh
head -10 file.txt | tail -1
tail -n+10 file.txt|head -1
```

用 `awk` 也是可以判断行号的。

```sh
awk 'NR == 10' file.txt
awk 'FNR == 10 {print }'  file.txt
```

其中 `FNR` 与 `NR` 不同的地方是多文件的时候，`FNR` 在每个文件都会重新变成 1。

还可以自己计数。

```sh
cnt=0
while read line && [ $cnt -le 10 ]; do
  let 'cnt = cnt + 1'
  if [ $cnt -eq 10 ]; then
    echo $line
    exit 0
  fi
done < file.txt
```
