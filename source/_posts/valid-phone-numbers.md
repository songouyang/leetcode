---
title: 193. Valid Phone Numbers
date: 2018-12-16 19:02:27
tags:
alias: 193/
---

找出符合条件的电话号码。

<!--more-->

用正则表达式即可。

```sh
grep -E -e "^[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}$" -e "^\([[:digit:]]{3}\)\ [[:digit:]]{3}-[[:digit:]]{4}$" file.txt
```

用 `grep` 需要注意它的一些正则表达式扩展。具体可以参考这里 [grep中使用"\d"匹配数字不成功的原因](https://blog.csdn.net/yufenghyc/article/details/51078107)。

还有人用 `sed` 和 `awk` 也完成了。

```sh
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
```
