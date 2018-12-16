---
title: 194. Transpose File
date: 2018-12-16 19:49:18
tags:
alias: 194/
---

将文件转置一下。

<!--more-->

基本上都是用 `awk` 来实现。使用 NF 个数组来存储每一列，最后输出每个数组。

```sh
awk '
    {
        for(i=1; i<=NF; i++)
        {   
            if(line[i] == "")
            {
                line[i] = $i
            }
            else
            {
                line[i] = line[i]" "$i
            }
        }
    }
    END{
         for(i=1; i<=NF; i++)
         {
             print line[i]
         }
       }
    ' file.txt
```
